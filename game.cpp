#include<SDL.h>
#include<iostream>
#include "player.h"

const int WIN_WIDTH = 800, WIN_HEIGHT = 600, FPS = 60;
bool running;

bool left, right, up, down;

void draw(SDL_Renderer * r);
void update();
void manageInput();

Player * p;
int speed = 5;

int main(int argc, char * args[]) {

	SDL_Window * win = NULL;
	SDL_Renderer * rend = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	win = SDL_CreateWindow("Winning is Losing", 
	SDL_WINDOWPOS_CENTERED, 
	SDL_WINDOWPOS_CENTERED, 
	WIN_WIDTH, WIN_HEIGHT, 0);
	
	rend = SDL_CreateRenderer(win, -1, 0);
	
	p = new Player(rend);
	
	running = true;
	double timeNow = SDL_GetTicks(), timeThen = timeNow, ticksPerUpdate = 1000.0d / FPS; // Used for timing.
	double delta = 0; // How many updates are needed.
	bool canRender = false;
	Uint32 timeOut = SDL_GetTicks() + 4000;
	int updates = 0, frames = 0; // Keeps track of the updates and framerate.
	
	while(running) {
		timeNow = SDL_GetTicks();
		delta += (timeNow - timeThen) / ticksPerUpdate;
		timeThen = timeNow;
		
		while(delta >= 1) {
			delta--;
			update();
			canRender = true;
			updates++;
		}
		
		if(canRender) {
			SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE); // Sets background to black.
			SDL_RenderClear(rend);
			draw(rend);
			SDL_RenderPresent(rend);
			canRender = false;
			frames++;
		}
		
		if(SDL_TICKS_PASSED(SDL_GetTicks(), timeOut)) {
			timeOut += 4000;
			SDL_Log("UPD: %d, FRM: %d", updates / 4, frames / 4); // Logs the update and framerate info.
			updates = 0;
			frames = 0;
		}
		
	}
	
	SDL_Quit();
	return 0;
}

void update() {
	manageInput();
	if(left) {
		p->rect.x -= speed;
	}
	if(right) {
		p->rect.x += speed;
	}
	if(up) {
		p->rect.y -= speed;
	}
	if(down) {
		p->rect.y += speed;
	}
}

void manageInput() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_WINDOWEVENT) {
			if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
				running = false; // Exits game loop and closes application.
			}
		}
		if(event.type == SDL_KEYDOWN) {
			if(event.key.keysym.sym == SDLK_a) {
				left = true;
			}
			if(event.key.keysym.sym  == SDLK_d) {
				right = true;
			}
			if(event.key.keysym.sym == SDLK_w) {
				up = true;
			}
			if(event.key.keysym.sym == SDLK_s) {
				down = true;
			}
		}
		if(event.type == SDL_KEYUP) {
			if(event.key.keysym.sym == SDLK_a) {
				left = false;
			}
			if(event.key.keysym.sym  == SDLK_d) {
				right = false;
			}
			if(event.key.keysym.sym == SDLK_w) {
				up = false;
			}
			if(event.key.keysym.sym == SDLK_s) {
				down = false;
			}
		}
	}
}

void draw(SDL_Renderer * r) {
	p->draw(r);
}