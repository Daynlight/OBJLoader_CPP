# C++ OBJLoader 
* <a href="#Usage">Usage</a>
* <a href="#Info">Info</a>
## <a id="Info">Info</a>
### Vertex Structure
Vectex
{
	vec3 Poses;
	vec2 Texures;
	vec3 Normals;
}
## <a id="Usage">Usage</a>
1. Import header File
* #include "path.LoadOBJ.h"
2. Create Object
* LoadOBJ ObjectName = LoadOBJ("PathToOBJFile");
3. Extract Indices from OBJ File
* int* ObjectIndicesName = ObjectName.Indices();
4. Export VertexArray from OBJ File
* VectexArray* ObjectVerticesName = ObjectName.Vertices();
5. Object VertexSize
* ObjectName.VerticesSize
6. Indices Size
* ObjectName.IndicesSize
<img width="100%" src="https://i.pinimg.com/originals/2b/07/f6/2b07f62987e987d4e53e84aa8b963b83.gif" />
