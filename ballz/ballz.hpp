#include <SDL2/SDL.h>

#include <string>

namespace ballz {

class Ballz {
private:
	std::string m_title;
	SDL_Window* m_window;
	SDL_GLContext m_context;

public:
	Ballz(const std::string &title = "Ballz");
	~Ballz();

	void run();
};

}