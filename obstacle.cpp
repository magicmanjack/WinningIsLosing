#include <SDL.h>
#include "obstacle.h"

Obstacle::Obstacle(SDL_Renderer * r, int x, int y) {
	rect.x = x;
	rect.y = y;
	rect.w = 100;
	rect.h = 100;
	flare = false;
}

void Obstacle::draw(SDL_Renderer * r) {
	SDL_SetRenderDrawColor(r, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(r, &rect);
	if(flare) {
		SDL_RenderFillRect(r, &rect);
		flare = false;
	}
}