#include "SDL.h"
#include "player.h"
#include <math.h>

Player::Player(SDL_Renderer * r) {
	SDL_Surface * sfce = SDL_LoadBMP("res\\Sprite.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	tx = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
	rect.x = 350;
	rect.y = 250;
	rect.w = 100;
	rect.h = 100;
	up = false;
	down = false;
	left = false;
	right = false;
	xVel = 0;
	yVel = 0;
	trueX = rect.x;
	trueY = rect.y;
}

void Player::draw(SDL_Renderer * r, int offsetX, int offsetY) {
	SDL_Rect offsRect = rect;
	offsRect.x += offsetX;
	offsRect.y += offsetY;
	SDL_RenderCopy(r, tx, NULL, &offsRect);
	SDL_SetRenderDrawColor(r, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(r, &offsRect);
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
		xVel -= ACC;
	}
	if(right) {
		xVel += ACC;
	}
	if(up) {
		yVel -=  ACC;
	}
	if(down) {
		yVel += ACC;
	}
	if(xVel > 0.0) {
		xVel -= (xVel * xVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
	}
	if(xVel < 0.0) {
		xVel += (xVel * xVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
	}
	if(yVel > 0.0) {
		yVel -= (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
	}
	if(yVel < 0.0) {
		yVel += (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
	}
	yVel += GRV; // Applies gravity to the yVel.
	trueX += xVel;
	trueY += yVel;
	rect.x = trueX;
	rect.y = trueY;
}