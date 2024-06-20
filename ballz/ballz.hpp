#include <SDL2/SDL.h>

namespace ballz {

class Ballz {
private:
	SDL_Window* m_window;

public:
	Ballz();
	~Ballz();

	void run();
};

}