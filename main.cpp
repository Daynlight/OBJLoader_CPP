
#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	Vec* Mapa = Map.GetVertices();
	int* Mapind = Map.GetIndices();
	for(int i =0;i<Map.size;i++)
	{
		std::cout << glm::to_string(Mapa[i].Pos) << " " << glm::to_string(Mapa[i].Tex) << " " << glm::to_string(Mapa[i].Nor) << std::endl;
	}
	for (int i = 0; i < Map.IndiesSize; i++)
	{
		std::cout << Mapind[i] << std::endl;
	}
	return 0;

};

