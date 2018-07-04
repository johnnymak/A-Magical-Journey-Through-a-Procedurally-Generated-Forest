
#define _CRT_NONSTDC_NO_WARNINGS
#pragma warning(disable:4996)

#include "CommonLibrary.h"
#include "Shaders/Shader.h"
#include "Camera.h"
#include "WorldMesh.h"
#include "Skybox.h"

using namespace std;


// ========== Function Prototypes ========== //

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void do_movement();
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
GLuint load2DTexture(GLchar* fileLocation);


// ========================= Shader File Paths ========================= // 

const GLchar * VERTEX_SHADER_PATH = "./Shaders/vertex.shader";
const GLchar * FRAGMENT_SHADER_PATH = "./Shaders/fragment.shader";

const GLchar * SKYBOX_VERTEX_SHADER = "./Shaders/skybox_vertex.shader";
const GLchar * SKYBOX_FRAGMENT_SHADER = "./Shaders/skybox_fragment.shader";



// ========== Constants and Values ========== //

// GLM Tranformations
glm::mat4 pvm;
glm::mat4 view;
glm::mat4 projection;

// Camera Object and movement
Camera camera(glm::vec3(0.0f, 5.0f, 15.0f));
bool keys[1024];
GLfloat lastX = 400, 
		lastY = 300;
bool firstMouse = true;
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

// Buffer Objects
GLuint VAO, VBO, normals_VBO, EBO;

// Light Position
glm::vec3 lightPos = glm::vec3(0.0f, 100.0f, 0.0f);



// ========== Main Method ========== //
int main() {

	srand(time(NULL));


	// Initiates GLFW and defines the settings
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glfwWindowHint(GLFW_SAMPLES, 4);

	// Creates Window Object 
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Comp371 - Group 7", nullptr, nullptr);
	if (window == nullptr) {
		cout << "Failed to create GLFW Windows\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	
	// Initiates GLEW (Extension Wrangler) 
	glewExperimental = GLU_TRUE;
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW\n";
		return -1;
	}

	// Creates the Viewport
	glViewport(0, 0, WIDTH, HEIGHT);

	// Enable Z-Buffer
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);



	// ========== Creating our shaders ========== //
	Shader ourShader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

	Shader skyboxShader(SKYBOX_VERTEX_SHADER, SKYBOX_FRAGMENT_SHADER);
	

	// ========== Creating Our Shapes ========== //
	WorldMesh world;
	vector<GLfloat>* vertices = world.getVertices();
	vector<GLuint>*  indices  = world.getIndices();
	vector<glm::vec3>* normals = world.getNormals();

	
	// Skybox
	Skybox skybox(&skyboxShader);	

	// Add fireflies
	Firefly fireflies(30);
	int num = fireflies.getNumber();
	vector<glm::vec3> positions = fireflies.getPositions();
	float scale;
	
	// Generate cubes for lights
	for (int i = 0; i < num; i++) {
		scale = 0.5f;
		Cube cu(scale, positions[i].x/scale, positions[i].y / scale, positions[i].z / scale, glm::vec3(1.0f, 1.0f, 1.0f)); // c'est blanc
		world.getVertexManager().updateMeshes(cu.getVertices(), cu.getIndices(), cu.getNormals());
	}


	// ========== Creating our Vertex Buffer Obj, Vertex Array Obj ========== //
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO); // Binds the VAO

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(GLfloat), &vertices->front(), GL_STATIC_DRAW);	// Copy our vertices to the buffer

	// Set the vertex attribute pointers : POSITION
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0);	
	glEnableVertexAttribArray(0);

	// Set the vertex attribute pointers : COLOR
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Set the vertex attribute pointers : TEXTURE COORDINATES
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// Set the vertex attribute pointers : TEXTURE OPACITY
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	//Creating the EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(GLuint), &indices->front(), GL_STATIC_DRAW);


	// ================ Creating the normals_VBO ================
	glGenBuffers(1, &normals_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, normals_VBO);
	glBufferData(GL_ARRAY_BUFFER, normals->size() * sizeof(glm::vec3), &normals->front(), GL_STATIC_DRAW);
	
	// Set the vertex attribute pointers : NORMALS
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(4);


	glBindVertexArray(0); // Unbinds the VAO


	// ===================== Textures ===================== //

	GLuint terrainTexture = load2DTexture("Textures/grass.png");
	GLuint dirtTexture = load2DTexture("Textures/dirt.png");

	// =============== Texture Location =============== // 
	vector<GLchar*> faces;
	faces.push_back("Textures/right.jpg");
	faces.push_back("Textures/left.jpg");
	faces.push_back("Textures/top.jpg");
	faces.push_back("Textures/bottom.jpg");
	faces.push_back("Textures/back.jpg");
	faces.push_back("Textures/front.jpg");

	skybox.loadCubeMap(faces);

	// ===================== Sunset ===================== //
	glm::vec3 sunset = glm::vec3(350.0f, 200.0f, -350.0f);
	glm::vec3 sunset2 = glm::vec3(350.0f, 200.0f, -110.0f);
	glm::vec3 sunset3 = glm::vec3(350.0f, 200.0f, 110.0f);
	glm::vec3 sunset4 = glm::vec3(350.0f, 200.0f, 210.0f);
	glm::vec3 sunset5 = glm::vec3(350.0f, 200.0f, 350.0f);

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// =============== Game Loop ================= //

	while (!glfwWindowShouldClose(window)) {

		// Check and call events
		glfwPollEvents();
		glfwSetKeyCallback(window, key_callback);
		glfwSetCursorPosCallback(window, mouse_callback);
		
		// Camera movement settings
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		do_movement();
		
		// Rendering Commands
		glClearColor((float)114 / (float)255, (float)220 / (float)255, (float)255 / (float)255, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ourShader.Use();

		// Using Textures
		glUniform1i(glGetUniformLocation(ourShader.Program, "grassTexture"), 0);
		glUniform1i(glGetUniformLocation(ourShader.Program, "dirtTexture"), 1);

		// Projection, View, Model 
		projection = glm::perspective(camera.Zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 1000.0f);
		view = camera.GetViewMatrix(); // Using camera view
		pvm = (projection) * (view);
		
		GLint lightPosLoc = glGetUniformLocation(ourShader.Program, "lightPos");
		GLint pvmLoc = glGetUniformLocation(ourShader.Program, "pvm");

		glUniformMatrix4fv(pvmLoc, 1, GL_FALSE, glm::value_ptr(pvm));
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

		// ===================== Fireflies ===================== //
		fireflies.draw(ourShader);

		// ===================== Sunset ===================== //
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset.position"), sunset.x, sunset.y, sunset.z);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset.ambient"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset.diffuse"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset.specular"), 1.0f, 0.0f, 0.00f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset.constant"), 0.005f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset.linear"), 0.00005);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset.quadratic"), 0.00005);

		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset2.position"), sunset2.x, sunset2.y, sunset2.z);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset2.ambient"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset2.diffuse"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset2.specular"), 1.0f, 0.0f, 0.00f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset2.constant"), 0.005f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset2.linear"), 0.00005);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset2.quadratic"), 0.00005);

		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset3.position"), sunset3.x, sunset3.y, sunset3.z);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset3.ambient"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset3.diffuse"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset3.specular"), 1.0f, 0.0f, 0.00f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset3.constant"), 0.005f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset3.linear"), 0.00005);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset3.quadratic"), 0.00005);

		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset4.position"), sunset4.x, sunset4.y, sunset4.z);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset4.ambient"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset4.diffuse"), 1.0f, 0.0f, 0.00f);
		glUniform3f(glGetUniformLocation(ourShader.Program, "sunset4.specular"), 1.0f, 0.0f, 0.00f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset4.constant"), 0.005f);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset4.linear"), 0.00005);
		glUniform1f(glGetUniformLocation(ourShader.Program, "sunset4.quadratic"), 0.00005);

		// Binding Our Textures to Use
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, terrainTexture);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, dirtTexture);


		// ==== Drawing out Objects =====
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, indices->size() * 2, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);


		// ==== Drawing Skybox =====
		skybox.draw(&camera, &view, &projection);

		// Swap the buffers
		glfwSwapBuffers(window);
	}

	// Frees up the buffers when done 
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();
	return 0;
}
// ========== End of Main Method ========== //


// Event handler on key press
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_ENTER) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	// Smooth camera transitions
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

// Mouse Movement Handler
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}


// Camera movement controls
void do_movement() {
	// Press W: Move Forward
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	// Press S: Move Backward
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	// Press A: Move Left
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	// Press D: Move Right
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
	// Press Space: Ascend the Camera 
	if (keys[GLFW_KEY_SPACE])
		camera.ProcessKeyboard(UP, deltaTime);
	// Press Left Control: Descent the Camera 
	if (keys[GLFW_KEY_LEFT_CONTROL])
		camera.ProcessKeyboard(DOWN, deltaTime);

	// Press Left Shift: Speed up Camera
	if (keys[GLFW_KEY_LEFT_SHIFT])
		camera.setCameraSpeed(camera.getDefaultSpeed() * 2);
	// Press C: Slow Down Camera
	else if (keys[GLFW_KEY_C])
		camera.setCameraSpeed(camera.getDefaultSpeed() / 2);
	// Default Speed
	else
		camera.setCameraSpeed(camera.getDefaultSpeed());
}

// Loading 2D Texture Function
GLuint load2DTexture(GLchar* fileLocation) {

	GLuint textureID;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int texWidth, texHeight;
	unsigned char* image = SOIL_load_image(fileLocation, &texWidth, &texHeight, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);


	return textureID;
}