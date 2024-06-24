#include "ballz.hpp"
#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>

namespace ballz {

Ballz::Ballz(const std::string& title) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WindowFlags flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	m_window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1920,
		1080,
		flags
	);

	SDL_GLContext context = SDL_GL_CreateContext(m_window);
	GLint res = glewInit();
	if (res != GLEW_OK) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(res) << std::endl;
		exit(1);
	}
	glClearColor(0.05f, 0.1f, 0.08f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(m_window);
}

Ballz::~Ballz() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Ballz::run() {
	SDL_Event event;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) ) {
				running = false;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex3d(-0.5, -0.5, 0.0);
		glVertex3d(0.5, -0.5, 0.0);
		glVertex3d(0.0, 0.5, 0.0);
		glEnd();

		SDL_GL_SwapWindow(m_window);
	}
}

}