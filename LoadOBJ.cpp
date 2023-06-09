#include "LoadOBJ.h"


LoadOBJ::LoadOBJ(const char* File)
{
    FilePath = File;
    std::ifstream DataSize(FilePath);
    std::string Line;
    while (std::getline(DataSize, Line))
    {
        std::stringstream LineArray(Line);
        std::string Word;
        while (LineArray >> Word) {
            if (Word == "v") VerticesSize++;
            if (Word == "f") IndicesSize += 3;
            if (Word == "vn") NoramlSize ++;
            if (Word == "vt") TextureSize ++;
        }
    }
    DataSize.close();

    int IndicesOrganise = 0;
    std::ifstream Data(FilePath);

    Indices = new GLuint[IndicesSize];
    Vertex* Vertices = new Vertex[VerticesSize];
    UVTexture* Texture = new UVTexture[TextureSize];
    Normals* Normal = new Normals[NoramlSize];
    FormatStatment* Format = new FormatStatment[VerticesSize * 2];
    VertexData = new VectexArray[VerticesSize];
    int VerticesID = 0;
    int TextureID = 0;
    int NormalsID = 0;
    int FormatID = 0;
    int ID = 0;
    while (std::getline(Data, Line))
    {
        int VerticesOrganise = 0;
        int TextureOrganise = 0;
        int NormalsOrganise = 0;
        int FormatOrganise = 0;
        float x = 0;
        float y = 0;
        float z = 0;
        std::stringstream LineArray(Line);
        std::string Word;
        while (LineArray >> Word)
        {

            if (IndicesOrganise == 1 || IndicesOrganise == 2 || IndicesOrganise == 3)
            {
                for (int i = 0; i < Word.length(); i++) if (Word[i] == '/') Word[i] = ' ';
                std::stringstream WordArray(Word);
                std::string WordFormat;
                while (WordArray >> WordFormat)
                {
                    Indices[ID] = std::stoi(WordFormat) - 1;
                    ID++;
                    break;
                }
                if (IndicesOrganise == 3) IndicesOrganise = 0; else IndicesOrganise++;
            }

            if (Word == "f")
            {
                IndicesOrganise++;
            }

            if (VerticesOrganise == 3)
            {
                z = std::stof(Word);
                Vertices[VerticesID] = Vertex{ glm::vec3(x,y,z) };
                VerticesID++;
                VerticesOrganise = 0;
            }
            if (VerticesOrganise == 2)
            {
                y = std::stof(Word);
                VerticesOrganise++;
            }
            if (VerticesOrganise == 1)
            {
                x = std::stof(Word);
                VerticesOrganise++;
            }
            if (Word == "v") VerticesOrganise++;

            if (NormalsOrganise == 3)
            {
                z = std::stof(Word);
                Normal[NormalsID] = Normals{ glm::vec3(x,y,z) };
                NormalsID++;
                NormalsOrganise = 0;
            }
            if (NormalsOrganise == 2)
            {
                y = std::stof(Word);
                NormalsOrganise++;
            }
            if (NormalsOrganise == 1)
            {
                z = std::stof(Word);
                NormalsOrganise++;
            }
            if (Word == "vn") NormalsOrganise++;

            if (TextureOrganise == 2)
            {
                y = std::stof(Word);
                Texture[TextureID] = UVTexture{ glm::vec2(x,y) };
                TextureID++;
                TextureOrganise = 0;
            }
            if (TextureOrganise == 1)
            {
                x = std::stof(Word);
                TextureOrganise++;
            }
            if (Word == "vt") TextureOrganise++;

            if (FormatOrganise == 1 || FormatOrganise == 2 || FormatOrganise == 3)
            {
                for (int i = 0; i < Word.length(); i++) if (Word[i] == '/') Word[i] = ' ';
                std::stringstream WordArray(Word);
                std::string WordFormat;
                int WordOrganise = 0;
                int ID = 0;
                int TextureFormatID = 0;
                int NormalsFormatID = 0;
                while (WordArray >> WordFormat)
                {

                    if (WordOrganise == 2)
                    {
                        NormalsFormatID = std::stoi(WordFormat) - 1;
                        Format[ID].NormalID = NormalsFormatID;
                        Format[ID].TextureID = TextureFormatID;
                        WordOrganise = 0;
                    }
                    if (WordOrganise == 1)
                    {
                        TextureFormatID = std::stoi(WordFormat) - 1;
                        WordOrganise++;
                    }
                    if (WordOrganise == 0)
                    {
                        ID = std::stoi(WordFormat) - 1;
                        WordOrganise++;
                    }
                }
                if (FormatOrganise == 3) FormatOrganise = 0; else FormatOrganise++;
            }
            if (Word == "f") FormatOrganise++;
        }

    }
    Data.close();
    for (int i = 0; i < VerticesSize; i++)
    {
        int TextureCreateVertexID = Format[i].TextureID;
        int NormalsCreateVertexID = Format[i].NormalID;
        VertexData[i] = VectexArray({ Vertices[i].Position,Texture[TextureCreateVertexID].UVTexture,Normal[NormalsCreateVertexID].Normals });
    }

}
