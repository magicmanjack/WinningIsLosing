#include <SDL.h>
#include "obstacle.h"

Obstacle::Obstacle(SDL_Renderer * r, int x, int y, const char * txFile) {
	if(txFile != NULL) {
		SDL_Surface * sfce = SDL_LoadBMP(txFile);
		SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
		tx = SDL_CreateTextureFromSurface(r, sfce);
		SDL_FreeSurface(sfce);
	}
	rect.x = x;
	rect.y = y;
	rect.w = 100;
	rect.h = 200;
	flare = false;
	
}

void Obstacle::draw(SDL_Renderer * r, int offsetX, int offsetY) {
	SDL_Rect offsRect = rect;
	offsRect.x += offsetX;
	offsRect.y += offsetY;
	SDL_SetRenderDrawColor(r, 255, 0, 0, SDL_ALPHA_OPAQUE);
	if(tx != NULL) {
		SDL_RenderCopy(r, tx, NULL, &offsRect);
	}
	/*
	SDL_RenderDrawRect(r, &offsRect);
	if(flare) {
		SDL_RenderFillRect(r, &offsRect);
		flare = false;
	}
	*/
}