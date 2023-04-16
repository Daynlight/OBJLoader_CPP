#include "Object.h"


void Object::Init(const char* Mesh, const char* TexturePATH, const char* Specular, const char* VarShader, const char* FragShader)
{
	const char* VertexData;
	const char* FragmentData;

	std::ifstream DataVertex(VarShader);
	std::string contentVertex;
	DataVertex.seekg(0, std::ios::end);
	contentVertex.resize(DataVertex.tellg());
	DataVertex.seekg(0, std::ios::beg);
	DataVertex.read(&contentVertex[0], contentVertex.size());
	DataVertex.close();
	VertexData = contentVertex.c_str();

	std::ifstream DataFragment(FragShader);
	std::string contentFragment;
	DataFragment.seekg(0, std::ios::end);
	contentFragment.resize(DataFragment.tellg());
	DataFragment.seekg(0, std::ios::beg);
	DataFragment.read(&contentFragment[0], contentFragment.size());
	DataFragment.close();
	FragmentData = contentFragment.c_str();

	GLuint vertexShaderProgram = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderProgram, 1, &VertexData, NULL);
	glCompileShader(vertexShaderProgram);

	GLuint fragmentShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderProgram, 1, &FragmentData, NULL);
	glCompileShader(fragmentShaderProgram);

	this->ShaderProgram = glCreateProgram();
	glAttachShader(this->ShaderProgram, vertexShaderProgram);
	glAttachShader(this->ShaderProgram, fragmentShaderProgram);
	glLinkProgram(this->ShaderProgram);
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);


	if(TexturePATH !="NULL") this->istexture = true;
	if(this->istexture)
	{
		glGenTextures(1, &this->texture);
		glBindTexture(GL_TEXTURE_2D, this->texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		stbi_set_flip_vertically_on_load(true);
		int ImageWidth, ImageHeight, ImageChannels;
		unsigned char* data = stbi_load(TexturePATH, &ImageWidth, &ImageHeight, &ImageChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ImageWidth, ImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);
	}



	LoadOBJ Object = LoadOBJ(Mesh);
	this->Indices = Object.Indices;
	this->IndicesSize = Object.IndicesSize;
	this->VerticesSize = Object.VerticesSize;
	this->Vertices = Object.VertexData;


	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);
	glBindVertexArray(this->VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->VerticesSize * sizeof(VectexArray), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->IndicesSize * sizeof(GLuint), Indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(
		0,                  
		3,                  
		GL_FLOAT,           
		GL_FALSE,          
		8 * sizeof(float),                 
		(void*)0            
	);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		1,                  
		3,                  
		GL_FLOAT,          
		GL_FALSE,           
		8 * sizeof(float),                  
		(void*)(3 * sizeof(float))            
	);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		2,                  
		3,                  
		GL_FLOAT,           
		GL_FALSE,           
		8 * sizeof(float),                 
		(void*)(5 * sizeof(float))       
	);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
void Object::Active()
{
	if (this->istexture) glBindTexture(GL_TEXTURE_2D, this->texture);
	glUseProgram(this->ShaderProgram);
}

void Object::Draw()
{
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->IndicesSize, GL_UNSIGNED_INT, 0);
}

void Object::Delete()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &VBO);
	glDeleteVertexArrays(1, &EBO);
	glDeleteTextures(1, &texture);
	glDeleteProgram(ShaderProgram);
}

