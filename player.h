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
		int speed;
};