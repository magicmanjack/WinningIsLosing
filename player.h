#include<SDL.h>

#ifndef _PLY_H_INCLUDED_
#define _PLY_H_INCLUDED_

class Player {
	public:
		Player(SDL_Renderer * r);
		SDL_Rect rect;
		SDL_Texture * tx, * txBk, * txCurrent;
		void update();
		void draw(SDL_Renderer * r, int offsetX, int offsetY);
		void shareInput(SDL_Event * e);
		bool left, right, up, down, space;
		double xVel, yVel; // The X and Y velocity of the player.
		double trueX, trueY; // A more accurate way of measuring the players position.
		const double TERMINAL_VEL = 5.0, ACC = 0.2, GRV = 0.01;
		int boundsW, boundsH;
		bool dead;
};

#endif