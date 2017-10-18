#pragma once

#include "utils.h"
#include "camera.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

struct VertexData {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

struct TextureData {
	unsigned int id;
	std::string type;
	aiString path;
	
};

class Mesh {
public:

	std::vector<VertexData> m_vertices;
	std::vector<unsigned int> m_indices;
	std::vector<TextureData> m_textures;

	Mesh(std::vector<VertexData> vertices, std::vector<unsigned int> indices, std::vector<TextureData> textures);
	void Draw(GLuint shader, Camera* camera);
private:

	GLuint m_VAO, m_VBO, m_EBO;

	void SetUpMesh();
};