#include<SDL.h>

class Player {
	public:
		Player(SDL_Renderer * r);
		SDL_Rect rect;
		SDL_Texture * tx;
		void update();
		void draw(SDL_Renderer * r);
		void shareInput(SDL_Event * e);
		bool left, right, up, down;
		double xVel, yVel; // The X and Y velocity of the player.
		double trueX, trueY; // A more accurate way of measuring the players position.
		const double TERMINAL_VEL = 5.0, ACC = 0.2, GRV = 0.01;
};