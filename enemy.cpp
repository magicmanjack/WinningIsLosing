#include <SDL.h>
#include <math.h>
#include "enemy.h"

SDL_Rect Enemy::target;

Enemy::Enemy(int x, int y, SDL_Renderer * r) {
	rect.x = x;
	rect.y = y;
	rect.w = 50;
	rect.h = 50;
	trueX = x;
	trueY = y;
	xVel = 0;
	yVel = 0;
	activated = false;
	SDL_Surface * sfce = SDL_LoadBMP("res\\bot.bmp");
	SDL_SetColorKey(sfce, SDL_TRUE, SDL_MapRGB(sfce->format, 0, 0, 0));
	tx = SDL_CreateTextureFromSurface(r, sfce);
	SDL_FreeSurface(sfce);
}

void Enemy::update() {
	int targetDistX = (rect.x  + (rect.w / 2)) - (target.x + (target.w / 2));
	int targetDistY = (rect.y  + (rect.h / 2)) - (target.y + (target.h / 2));
	
	int targetDist = sqrt ((targetDistX * targetDistX) + (targetDistY * targetDistY));
	
	if(targetDist < ACT_RADIUS) {
		
		activated = true;
		
		if(targetDistX > 0) {
			xVel -= ACC;
		}else if(targetDistX < 0) {
			xVel += ACC;
		}
	
		if(targetDistY > 0) {
			yVel -= ACC;
		}else if(targetDistY < 0) {
			yVel += ACC;
		}
	
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
	if(activated) {
		yVel += GRV;
	}
	trueX += xVel;
	trueY += yVel;
	rect.x = trueX;
	rect.y = trueY;
}

void Enemy::draw(SDL_Renderer * r, int offsetX, int offsetY) {
	SDL_Rect offsRect = rect;
	offsRect.x += offsetX;
	offsRect.y += offsetY;
	SDL_RenderCopy(r, tx, NULL, &offsRect);
	SDL_SetRenderDrawColor(r, 255, 0, 0, SDL_ALPHA_OPAQUE);
	//SDL_RenderDrawRect(r, &offsRect);
}