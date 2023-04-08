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
    FormatBlock* Format = new FormatBlock[size];
    int i = 0;
    int itex = 0;
    int inor = 0;
    int ifor = 0;
    while (std::getline(data, line))
    {
        std::stringstream lineArray(line);
        std::string word;
        int sekVert = 0;
        int sekTex = 0;
        int sekNor = 0;
        int sekFormat = 0;
        float z = 0;
        float y = 0;
        float x = 0;

        while (lineArray >> word) {
            if (sekVert == 3)
            {
                 z = std::stof(word);
                 vertices[i] = Vertex{ glm::vec3(x,y,z) };
                 i++;
                 sekVert = 0;
            }
            if (sekVert == 2)
            {
                y = std::stof(word);
                sekVert++;
            }
            if (sekVert == 1)
            {
               
                x = std::stof(word);
                sekVert++;
            }
            if (word == "v")
            {
                sekVert++;
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
                y = std::stof(word);
                Texture[itex] = UVTexture{ glm::vec2(x,y) };
                itex++;
                sekTex = 0;
            }
            if (sekTex == 1)
            {
                x = std::stof(word);
                sekTex++;
            }
            if (word == "vt")
            {
                sekTex++;
            }


            if (sekFormat == 1 || sekFormat == 2 || sekFormat == 3)
            {
                for (int i = 0; i < word.length(); i++)
                {
                    if (word[i] == '/') 
                    {
                        word[i] = ' ';
                    }
                }
                std::stringstream wordArray(word);
                std::string wordFormat;
                int wordsek = 0;
                int id = 0;
                int texid = 0;
                int normalid = 0;
                while (wordArray >> wordFormat)
                {
                   
                    if (wordsek == 2)
                    {
                        normalid = std::stoi(wordFormat)-1;
                        Format[id].normalid = normalid;
                        Format[id].textureid = texid;
                        
                        wordsek = 0;
                    }
                    if (wordsek == 1)
                    {
                        texid= std::stoi(wordFormat)-1;
                        wordsek++;
                    }
                    if (wordsek == 0)
                    {
                        id = std::stoi(wordFormat)-1;
                        
                        wordsek++;
                    } 
                }
                if (sekFormat == 3) sekFormat = 0;
                else sekFormat++;
            }
            if (word == "f")
            {
                sekFormat++;
            }
        }
    }
    Vec* vec = new Vec[size];
    for (int i = 0; i < size; i++)
    {
        vec[i] = Vec({ vertices[i].Position,Texture[Format[i].textureid].UVTexture,Normal[Format[i].normalid].Normals});
    }

    return vec;
}
