#include <SDL.h>

#ifndef _OBST_H_DEF_
#define _OBST_H_DEF_

class Obstacle {
	public:
		Obstacle(SDL_Renderer * r, int x, int y);
		SDL_Rect rect;
		SDL_Texture * tx;
		void draw(SDL_Renderer * r);
		bool flare; // For debugging purposes.
};

#endif