#include "SDL.h"
#include "player.h"
#include <math.h>

Player::Player(SDL_Renderer * r) {
	SDL_Surface * sfce = SDL_LoadBMP("res\\plyr.bmp"); // Loads texture
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0)); // Sets the transparent colour value.
	tx = SDL_CreateTextureFromSurface(r, sfce); // Sets the texture.
	sfce = SDL_LoadBMP("res\\plyr_bk.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	txBk = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
	txCurrent = tx; // Sets the starting texture of the animation.
	rect.x = 350;
	rect.y = 250;
	rect.w = 100;
	rect.h = 100;
	up = false;
	down = false;
	left = false;
	right = false;
	space = false;
	xVel = 0;
	yVel = 0;
	trueX = rect.x;
	trueY = rect.y;
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
		xVel -= ACC; // Adds acceleration to the x component of velocity.
	}
	if(right) {
		xVel += ACC; // Adds acceleration to the x component of velocity.
	}
	if(up) {
		yVel -=  ACC; // Adds acceleration to the y component of velocity.
	}
	if(down) {
		yVel += ACC; // Adds acceleration to the y component of velocity.
	}
	if(xVel > 0.0) {
		xVel -= (xVel * xVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC); // Deceleration of x component. Also applies terminal velocity.
		txCurrent = tx;
	}
	if(xVel < 0.0) {
		xVel += (xVel * xVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC); // Deceleration of x component. Also applies terminal velocity.
		txCurrent = txBk;
	}
	if(yVel > 0.0) {
		yVel -= (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC); // Deceleration of y component. Also applies terminal velocity.
	}
	if(yVel < 0.0) {
		yVel += (yVel * yVel) / ((TERMINAL_VEL * TERMINAL_VEL) / ACC); // Deceleration of y component. Also applies terminal velocity.
	}

	yVel += GRV; // Applies gravity to the yVel.
	trueX += xVel; // The velocity is added to trueX before rect.x because is has double precesision and doesn't round to nearest int.
	trueY += yVel; // Same here as the latter.
	rect.x = trueX;
	rect.y = trueY;
}