#include "ballz.hpp"
#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>

namespace ballz {

Ballz::Ballz() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WindowFlags flags = static_cast<SDL_WindowFlags>(SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	m_window = SDL_CreateWindow(
		"Ballz",
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
	}
}

}