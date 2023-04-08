
#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	Vec* Mapa = Map.GetVertices();
	for(int i =0;i<4;i++)
	{

		std::cout << glm::to_string(Mapa[i].Pos) << " " << glm::to_string(Mapa[i].Tex) << " " << glm::to_string(Mapa[i].Nor) << std::endl;
	}
	return 0;

};

