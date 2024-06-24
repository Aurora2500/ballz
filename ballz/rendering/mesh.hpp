#include <vector>

#include <glm/glm.hpp>

namespace ballz {

struct vertex2d {
	glm::vec2 position;
	glm::vec2 tex_coords;

	static void attrib(unsigned int vao, unsigned int vbo);
};

template <typename V>
struct mesh {
	std::vector<V> vertices;
	std::vector<unsigned int> indices;

	unsigned int vao, vbo, ebo;

	void create_mesh();

	void draw();
};

using mesh2d = mesh<vertex2d>;

}