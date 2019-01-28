#include <SDL.h>

#ifndef _FINISH_LINE_H_
#define _FINISH_LINE_H_

class FinishLine {
	public:
		FinishLine(SDL_Renderer * r, int x);
		SDL_Rect rect;
		SDL_Texture * tx;
		bool activated;
		void draw(SDL_Renderer * r, int offsetX, int offsetY);
};

#endif