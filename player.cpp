#include "SDL.h"
#include "player.h"
#include <math.h>

Player::Player(SDL_Renderer * r) {
	SDL_Surface * sfce = SDL_LoadBMP("res\\plyr.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	tx = SDL_CreateTextureFromSurface(r, sfce);
	sfce = SDL_LoadBMP("res\\plyr_bk.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	txBk = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
	txCurrent = tx;
	rect.x = 350;
	rect.y = 250;
	rect.w = 100;
	rect.h = 100;
	boundsW = 800;
	boundsH = 600;
	up = false;
	down = false;
	left = false;
	right = false;
	space = false;
	xVel = 0;
	yVel = 0;
	trueX = rect.x;
	trueY = rect.y;
	dead = false;
}

void Player::draw(SDL_Renderer * r, int offsetX, int offsetY) {
	SDL_Rect offsRect = rect;
	offsRect.x += offsetX;
	offsRect.y += offsetY;
	SDL_RenderCopy(r, txCurrent, NULL, &offsRect);
	SDL_SetRenderDrawColor(r, 0, 255, 0, SDL_ALPHA_OPAQUE);
	// SDL_RenderDrawRect(r, &offsRect);
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
			if(e -> key.keysym.sym == SDLK_SPACE) {
				space = true;
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
			if(e -> key.keysym.sym == SDLK_SPACE) {
				space = false;
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
		txCurrent = tx;
	}
	if(xVel < 0.0) {
		xVel += (xVel * xVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
		txCurrent = txBk;
	}
	if(yVel > 0.0) {
		yVel -= (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
		if(trueY + rect.h >= boundsH) {
			yVel = 0; // Stops the player from going off the screen;
		}
	}
	if(yVel < 0.0) {
		yVel += (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC);
		if(trueY <= 0) {
			yVel = 0; // Stops the player from going off the screen;
		}
	}

	yVel += GRV; // Applies gravity to the yVel.
	trueX += xVel;
	trueY += yVel;
	rect.x = trueX;
	rect.y = trueY;
}