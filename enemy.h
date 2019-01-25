#include <SDL.h>

#ifndef _ENEM_H_DEFINED_
#define _ENEM_H_DEFINED_

class Enemy {
	public:
		Enemy(int x, int y, SDL_Renderer * r);
		SDL_Rect rect;
		SDL_Texture * tx;
		double trueX, trueY, xVel, yVel;
		static SDL_Rect target; // The target to follow.
		void update();
		void draw(SDL_Renderer * r, int offsetX, int offsetY);
		const double TERMINAL_VEL = 3.0, ACC = 0.1, GRV = 0.01, ACT_RADIUS = 300;
		bool activated;
};

#endif