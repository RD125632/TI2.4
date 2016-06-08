#pragma once

#include <GL/glew.h>
#include <string.h>
#include <map>
#include <vector>


class ShaderProgram
{
	class Shader
	{
	public:
		GLuint shaderId;
		Shader(std::string fileName, GLenum type);
	};


	GLuint programId;
	std::vector<Shader*> shaders;

	std::map<std::string, int> uniformLocations;

public:
	ShaderProgram(std::string vertShader, std::string fragShader);
	ShaderProgram(std::string vertShader, std::string fragShader, std::string geometryShader);
	~ShaderProgram();

	void addVertexShader(std::string filename);
	void addFragmentShader(std::string filename);
	void addGeometryShader(std::string filename);
	//attributes
	void bindAttributeLocation(std::string name, int position);
	void bindFragLocation(std::string name, int position);
	//uniforms
	GLuint getUniformLocation(const std::string &);
	void setUniformFloat(const std::string &name, float value);

	void link();
	void use();
	static bool hasShaders();
};
