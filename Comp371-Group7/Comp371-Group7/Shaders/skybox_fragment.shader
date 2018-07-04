#version 330 core

// Skybox Fragment Shader Input
in vec3 TexCoords;

// Skybox Fragment Shader Output
out vec4 color;

// Skybox Fragment Shader Uniform
uniform samplerCube skybox;

// Main Method
void main() {    
    color = texture(skybox, TexCoords);
}