#include "LoadOBJ.h"


LoadOBJ::LoadOBJ(const char* File)
{
    DataFile = File;
	std::ifstream data(DataFile);
	std::string line;
    
    while (std::getline(data, line))
    {
        std::stringstream lineArray(line);
        std::string word;
        while (lineArray >> word) {
            if (word == "v")
            {
                size++;
            }
        }
    }

}

void LoadOBJ::GetIndices()
{
}

Vertex* LoadOBJ::GetVertices()
{
    std::ifstream data(DataFile);
    std::string line;
    Vertex* vertices = new Vertex[size];
    int i = 0;
    while (std::getline(data, line))
    {
        std::stringstream lineArray(line);
        std::string word;
        int sek = 0;
        float z = 0;
        float y = 0;
        float x = 0;
        while (lineArray >> word) {
            if (sek == 3)
            {
                 z = std::stof(word);
                 vertices[i] = Vertex{ glm::vec3(x,y,z) };

                 i++;
                 sek = 0;
            }
            if (sek == 2)
            {
                y = std::stof(word);
                sek++;
            }
            if (sek == 1)
            {
               
                x = std::stof(word);
                sek++;
            }
            if (word == "v")
            {
                sek++;
            }
        }
    }
    return vertices;
}
