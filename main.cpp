#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	VectexArray* Mapa = Map.VertexData;
	GLuint* Mapind = Map.Indices;
	for(int i =0;i<Map.VerticesSize;i++) std::cout 
	<< glm::to_string(Mapa[i].Poses) << " " << glm::to_string(Mapa[i].Texures) 
	<< " " << glm::to_string(Mapa[i].Normals) << std::endl;
	for (int i = 0; i < Map.IndicesSize; i++) std::cout << Mapind[i] << std::endl;

	return 0;
};

