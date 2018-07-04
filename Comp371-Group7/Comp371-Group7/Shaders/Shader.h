
#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// GLEW 
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

using namespace std;

class Shader {

	public:

		GLuint Program;

		// Constructor reads and builds the shader
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {

			string vertexCode;
			string fragmentCode;
			
			ifstream vShaderFile;
			vShaderFile.exceptions(ifstream::badbit);

			ifstream fShaderFile;
			fShaderFile.exceptions(ifstream::badbit);

			try {
				// Opening the Files
				vShaderFile.open(vertexPath);
				fShaderFile.open(fragmentPath);
				stringstream vShaderStream, fShaderStream;

				// Reading the Files
				vShaderStream << vShaderFile.rdbuf();
				fShaderStream << fShaderFile.rdbuf();

				// Closing file handler
				vShaderFile.close();
				fShaderFile.close();

				// Convert stream into string
				vertexCode = vShaderStream.str();
				fragmentCode = fShaderStream.str();

			} catch (ifstream::failure e) {
				cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
			}
			
			// ===== Compiling Our Shaders ===== //
			GLint  success;
			GLchar infoLog[512];
			char const * vShaderCode = vertexCode.c_str();
			char const * fShaderCode = fragmentCode.c_str();
			
			// Compiling Vertex Shader
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vShaderCode, NULL);
			glCompileShader(vertex);

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);		// Check for error
			if (!success) {
				glGetShaderInfoLog(vertex, 512, NULL, infoLog);
				cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
			}

			// Compiling Fragment Shader
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fShaderCode, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);	// Check for error
			if (!success) {
				glGetShaderInfoLog(fragment, 512, NULL, infoLog);
				cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
			}

			// Shader Program
			this->Program = glCreateProgram();
			glAttachShader(this->Program, vertex);
			glAttachShader(this->Program, fragment);
			glLinkProgram(this->Program);
			
			glGetProgramiv(this->Program, GL_LINK_STATUS, &success);	// Check for error
			if (!success) {
				glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
				cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
			}

			// Deleting Vertex/Fragment shader after linking
			glDeleteShader(vertex);
			glDeleteShader(fragment);

		}

		// Use the program
		void Use() {
			glUseProgram(this->Program);
		}
};

#endif