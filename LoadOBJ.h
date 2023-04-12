#pragma once
#include "Lib/include/glm/gtx/string_cast.hpp"
#include "Lib/include/glm/glm.hpp"
#include "LIB/include/glad/glad.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

struct Vertex
{
	glm::vec3 Position;
};
struct UVTexture
{
	glm::vec2 UVTexture;
};
struct Normals
{
	glm::vec3 Normals;
};
struct FormatStatment
{
	int NormalID;
	int TextureID;
};
struct VectexArray
{
	glm::vec3 Poses;
	glm::vec2 Texures;
	glm::vec3 Normals;
};

class LoadOBJ
{
public:
	LoadOBJ(const char* File);
	GLuint* Indices();
	VectexArray* Vertices();

	int VerticesSize = 0;
	int IndicesSize = 0;
	const char* FilePath;
};

