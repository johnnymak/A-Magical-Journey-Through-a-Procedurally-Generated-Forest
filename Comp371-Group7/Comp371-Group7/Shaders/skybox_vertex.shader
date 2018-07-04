#version 330 core

// Skybox Vertex Shader Input
layout (location = 0) in vec3 position;

// Skybox Vertex Shader Output
out vec3 TexCoords;

// Skybox Vertex Shader Uniform Variables
uniform mat4 projection;
uniform mat4 view;

// Main Method
void main() {
    vec4 pos = projection * view * vec4(position, 1.0);

    gl_Position = pos.xyww;
    TexCoords = position;
}  