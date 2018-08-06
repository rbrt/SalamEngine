
#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include <string>
#include <vector>


class ModelLoader
{
	public:
		ModelLoader() {}
		void LoadModel(std::string path);
		int getVertexCount() { return elementCount / dataPerVertex; }
		int getElementCount() { return elementCount; };

		float* getModelData() { return modelData.data(); }

		const std::vector<float>* getModelDataVector() { return &modelData; }

	private:
		void addVertex(float vertexX, float vertexY, float vertexZ,
					   float normalX, float normalY, float normalZ,
					   float texcoordX, float texcoordY);

		int elementCount = 0;
		const int dataPerVertex = 8;
		std::vector<float> modelData;
};