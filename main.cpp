
#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	Vertex* Mapa = Map.GetVertices();
	std::cout << (Mapa[1].Position.x);
	return 0;
};

