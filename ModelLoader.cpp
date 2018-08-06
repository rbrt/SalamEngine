#include "ModelLoader.h"
#include <iostream>
#include "tiny_obj_loader.h"

void ModelLoader::LoadModel(std::string path)
{
	modelData.push_back(0.0f);
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;

	bool loadSuccess = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, path.c_str());

	if (!err.empty()) { // `err` may contain warning message.
		std::cerr << err << std::endl;
	}

	if (!loadSuccess) {
		cout << "Loading model at path: " << path << " failed." << endl;
		exit(1);
	}

	// Loop over shapes
	for (size_t s = 0; s < shapes.size(); s++) 
	{
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) 
		{
			int fv = shapes[s].mesh.num_face_vertices[f];

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) 
			{
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				
				
				tinyobj::real_t nx = 0;
				tinyobj::real_t ny = 0;
				tinyobj::real_t nz = 0;
				tinyobj::real_t tx = 0;
				tinyobj::real_t ty = 0;
				tinyobj::real_t red = 0;
				tinyobj::real_t green = 0;
				tinyobj::real_t blue = 0;

				// Vertex coords
				tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
				tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
				tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
				
				// Normals
				if (attrib.normals.size() >= 3)
				{
					nx = attrib.normals[3 * idx.normal_index + 0];
					ny = attrib.normals[3 * idx.normal_index + 1];
					nz = attrib.normals[3 * idx.normal_index + 2];
				}
				
				// Texcoords
				if (attrib.texcoords.size() >= 2)
				{
					tx = attrib.texcoords[2 * idx.texcoord_index + 0];
					ty = attrib.texcoords[2 * idx.texcoord_index + 1];
				}
				
				// Vertex colours
				if (attrib.texcoords.size() >= 3)
				{
					red = attrib.colors[3 * idx.vertex_index + 0];
					green = attrib.colors[3 * idx.vertex_index + 1];
					blue = attrib.colors[3 * idx.vertex_index + 2];
				}

				addVertex(vx, vy, vz, nx, ny, nz, tx, ty);
			}
			index_offset += fv;
		}
	}

	cout << "Loading Complete" << endl;
}

void ModelLoader::addVertex(float vertexX, float vertexY, float vertexZ,
							float normalX, float normalY, float normalZ,
							float texcoordX, float texcoordY)
{
	if (modelData.size() - 8 <= elementCount)
	{
		modelData.resize(modelData.size() + 10000);
	}

	tinyobj::real_t *p = modelData.data() + elementCount;
	*p++ = vertexX;
	*p++ = vertexY;
	*p++ = vertexZ;
	//*p++ = normalX;
	//*p++ = normalY;
	//*p++ = normalZ;
	//*p++ = texcoordX;
	//*p++ = texcoordY;


	//cout << vertexX << ", " << vertexY << ", " << vertexZ << ", " << endl;

	elementCount += 8;
}