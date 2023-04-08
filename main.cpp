
#include "main.h"


int main()
{
	LoadOBJ Map = LoadOBJ("Assets/Map/object.obj");
	Vec* Mapa = Map.GetVertices();
	std::cout << Mapa[0].Tex.x << std::endl;
	return 0;

};

