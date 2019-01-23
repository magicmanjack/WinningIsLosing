#include <SDL.h>

class Obstacle {
	public:
		Obstacle(SDL_Renderer * r, int x, int y);
		SDL_Rect rect;
		SDL_Texture * tx;
		void draw(SDL_Renderer * r);
};