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
	speed = 5;
	up = false;
	down = false;
	left = false;
	right = false;
}

void Player::draw(SDL_Renderer * r) {
	SDL_SetRenderDrawColor(r, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(r, &rect);
	SDL_RenderCopy(r, tx, NULL, &rect);
}

void Player::shareInput(SDL_Event * e) {
	if(e -> type == SDL_KEYDOWN) {
			if(e -> key.keysym.sym == SDLK_a) {
				left = true;
			}
			if(e -> key.keysym.sym  == SDLK_d) {
				right = true;
			}
			if(e -> key.keysym.sym == SDLK_w) {
				up = true;
			}
			if(e -> key.keysym.sym == SDLK_s) {
				down = true;
			}
		}
		if(e -> type == SDL_KEYUP) {
			if(e -> key.keysym.sym == SDLK_a) {
				left = false;
			}
			if(e -> key.keysym.sym  == SDLK_d) {
				right = false;
			}
			if(e -> key.keysym.sym == SDLK_w) {
				up = false;
			}
			if(e -> key.keysym.sym == SDLK_s) {
				down = false;
			}
		}
}

void Player::update() {
	if(left) {
		rect.x -= speed;
	}
	if(right) {
		rect.x += speed;
	}
	if(up) {
		rect.y -= speed;
	}
	if(down) {
		rect.y += speed;
	}
}