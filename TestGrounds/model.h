#pragma once

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "mesh.h"

class Model
{
public:
	Camera* m_camera;
	GLuint m_shader;

	Model(GLchar* path, Camera* camera, GLuint program);
	void Draw();

private:
	std::vector<Mesh> meshes;
	std::string directory;
	std::vector<TextureData> textures_loaded;

	void LoadModel(std::string path);
	void ProcessNode(aiNode *node, const aiScene *scene);
	Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<TextureData> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	GLint TextureFromFile(const char* path, std::string directory);
};