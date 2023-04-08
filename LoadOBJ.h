#pragma once
#include "LIB/include/glm/glm.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "LIB/include/glm/gtx/string_cast.hpp"

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
struct FormatBlock
{
	int normalid;
	int textureid;
};
struct Vec
{
	glm::vec3 Pos;
	glm::vec2 Tex;
	glm::vec3 Nor;
};
 
class LoadOBJ
{
public:
	LoadOBJ(const char* File);
	void GetIndices();
	Vec* GetVertices();

	int size = 0;
	const char* DataFile;
};

