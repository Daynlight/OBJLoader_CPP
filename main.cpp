
#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	Vec* Mapa = Map.GetVertices();
	std::cout << glm::to_string(Mapa[0].Pos) << " "<< glm::to_string(Mapa[0].Tex) << " "<< glm::to_string(Mapa[0].Nor) << std::endl;
	return 0;

};

