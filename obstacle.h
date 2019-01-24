#include <SDL.h>

#ifndef _OBST_H_DEF_
#define _OBST_H_DEF_

class Obstacle {
	public:
		Obstacle(SDL_Renderer * r, int x, int y, const char * txFile);
		SDL_Rect rect;
		SDL_Texture * tx;
		void draw(SDL_Renderer * r, int offsetX, int offsetY);
		bool flare; // For debugging purposes.
};

#endif