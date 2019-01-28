#include "finishLine.h"

FinishLine::FinishLine(SDL_Renderer * r, int x) {
	rect.x = x;
	rect.y = 0;
	rect.w = 100;
	rect.h = 600;
	SDL_Surface * sfce = SDL_LoadBMP("res\\finish_line.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	tx = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
	activated = false;
}

void FinishLine::draw(SDL_Renderer * r, int offsetX, int offsetY) {
	SDL_Rect offsRect = rect;
	offsRect.x += offsetX;
	offsRect.y += offsetY;
	SDL_RenderCopy(r, tx, NULL, &offsRect);
	SDL_SetRenderDrawColor(r, 0, 255, 0, SDL_ALPHA_OPAQUE);
}