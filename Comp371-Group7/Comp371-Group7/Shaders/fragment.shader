
#version 330 core

// Point Light Structure
struct PointLight {
	vec3 position;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

// Number of Point Lights around the map
#define NR_POINT_LIGHTS 30

// Fragment Shader Input
in vec3 ourFragPos;
flat in vec3 ourColor;
flat in vec3 ourNormal;
in vec2 outTexCoord;
in float outOpacity;

// Uniform Variables 
uniform sampler2D terrainTexture;
uniform sampler2D dirtTexture;

uniform vec3 viewPos;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform PointLight sunset;
uniform PointLight sunset2;
uniform PointLight sunset3;
uniform PointLight sunset4;
uniform vec3 lightPos;

// Fragment Shader Outputs
out vec4 color;

// Function prototypes
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

// Main Method
void main() {
	// Properties
	vec3 norm = normalize(ourNormal);
	vec3 viewDir = normalize(viewPos - ourFragPos);
	vec3 lightColor = vec3(0.8158f, 0.8941f, 1.0f); // blueish
	vec3 objectColor = ourColor;
	vec3 result;
	result = CalcPointLight(sunset, norm, ourFragPos, viewDir);
	result += CalcPointLight(sunset2, norm, ourFragPos, viewDir);
	result += CalcPointLight(sunset3, norm, ourFragPos, viewDir);
	result += CalcPointLight(sunset4, norm, ourFragPos, viewDir);

	for (int i = 0; i < NR_POINT_LIGHTS; i++)
		result += CalcPointLight(pointLights[i], norm, ourFragPos, viewDir);
	
	// === ATTENUATION ===
	float distance = length(lightPos - ourFragPos);
	float attenuation = 1.0f / (1.0 + 0.000007 * distance + 0.0000007 * distance * distance);

	// === AMBIENT ===
	float ambientStrength = 0.7f;
	vec3 ambient = attenuation * ambientStrength * lightColor;

	// === DIFFUSE ===
	float diff = max(dot(norm, viewDir), 0.0f);
	float diffuseStrength = 0.8f;
	vec3 diffuse = attenuation * diffuseStrength * diff * lightColor;

	//result += (ambient + diffuse) * objectColor;
	result += ambient * objectColor;

	if (outOpacity > 1.0f) {
		color = vec4(result, 1.0f);
	}

	else {
		color = mix(texture(terrainTexture, outTexCoord), texture(dirtTexture, outTexCoord), outOpacity) * vec4(result, 1.0f);
	}
}


// Calculates the color when using a point light.
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
	vec3 lightDir = normalize(light.position - fragPos);
	// Diffuse shading
	float diff = max(dot(normal, lightDir), 0.0);
	
	// Attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	// Combine results
	vec3 ambient = light.ambient * vec3(texture(terrainTexture, outTexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(terrainTexture, outTexCoord));
	//vec3 ambient = light.ambient ;
	//vec3 diffuse = light.diffuse * diff ;
	ambient *= attenuation;
	diffuse *= attenuation;
	return (ambient + diffuse);
}
