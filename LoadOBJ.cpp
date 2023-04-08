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

Vec* LoadOBJ::GetVertices()
{
    std::ifstream data(DataFile);
    std::string line;
    Vertex* vertices = new Vertex[size];
    UVTexture* Texture = new UVTexture[size];
    Normals* Normal = new Normals[size];
    int i = 0;
    int itex = 0;
    int inor = 0;
    while (std::getline(data, line))
    {
        std::stringstream lineArray(line);
        std::string word;
        int sek = 0;
        int sekTex = 0;
        int sekNor = 0;
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

            if (sekNor == 3)
            {
                z = std::stof(word);
                Normal[inor] = Normals{ glm::vec3(x,y,z) };
                inor++;
                sekNor = 0;
            }
            if (sekNor == 2)
            {
                y = std::stof(word);
                sekNor++;
            }
            if (sekNor == 1)
            {
                z = std::stof(word);
                sekNor++;
            }
            if (word == "vn")
            {
                sekNor++;
            }

            if (sekTex == 2)
            {
                x = std::stof(word);
                Texture[itex] = UVTexture{ glm::vec2(x,y) };
                itex++;
                sekTex = 0;
            }
            if (sekTex == 1)
            {
                y = std::stof(word);
                sekTex++;
            }
            if (word == "vt")
            {
                sekTex++;
            }
        }
    }

    Vec* vec = new Vec[size];

    for (int i = 0; i < size; i++)
    {
        vec[i] = Vec({ vertices[i].Position,Texture[i].UVTexture,Normal[i].Normals});
    }


    return vec;
}
