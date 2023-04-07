#pragma once
#include "LIB/include/glm/glm.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Lib/include/glm/gtx/string_cast.hpp"

struct Vertex
{
	glm::vec3 Position;
};

class LoadOBJ
{
public:
	LoadOBJ(const char* File);
	void GetIndices();
	Vertex* GetVertices();

	int size = 0;
	const char* DataFile;
};

