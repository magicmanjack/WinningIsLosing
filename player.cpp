#include "SDL.h"
#include "player.h"

Player::Player(SDL_Renderer * r) {
	SDL_Surface * sfce = SDL_LoadBMP("res\\Sprite.bmp");
	tx = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
	rect.x = 350;
	rect.y = 250;
	rect.w = 100;
	rect.h = 100;
}

void Player::draw(SDL_Renderer * r) {
	SDL_SetRenderDrawColor(r, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(r, &rect);
	SDL_RenderCopy(r, tx, NULL, &rect);
}