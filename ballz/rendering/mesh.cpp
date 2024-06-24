#include "mesh.hpp"

#include <GL/glew.h>
#include <GL/gl.h>

namespace ballz {

void vertex2d::attrib(unsigned int vao, unsigned int vbo) {
	glEnableVertexArrayAttrib(vao, 0);
	glEnableVertexArrayAttrib(vao, 1);
	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayAttribBinding(vao, 1, 0);
	glVertexArrayAttribFormat(vao, 0, 2, GL_FLOAT, GL_FALSE, offsetof(vertex2d, position));
	glVertexArrayAttribFormat(vao, 1, 2, GL_FLOAT, GL_FALSE, offsetof(vertex2d, tex_coords));
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(vertex2d));
}

template <typename V>
void mesh<V>::create_mesh() {
	glCreateVertexArrays(1, &vao);

	unsigned int[2] buffers;
	glCreateBuffers(1, buffers);
	vbo = buffers[0];
	ebo = buffers[1];

	glNamedBufferData(
			vbo,
			vertices.size() * sizeof(V),
			vertices.data(),
			GL_STATIC_DRAW);
	V::attrib(vao, vbo);
	glNamedBufferData(
			ebo,
			indices.size() * sizeof(unsigned int),
			indices.data(),
			GL_STATIC_DRAW);
	glVertexArrayElementBuffer(vao, ebo);
}

}