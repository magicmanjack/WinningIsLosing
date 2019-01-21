#include<SDL.h>
#include<iostream>

const int WIN_WIDTH = 800, WIN_HEIGHT = 600;

int main(int argc, char * args[]) {

	SDL_Window * win = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	win = SDL_CreateWindow("Winning is Losing", 
	SDL_WINDOWPOS_CENTERED, 
	SDL_WINDOWPOS_CENTERED, 
	WIN_WIDTH, WIN_HEIGHT, 0);
	
	SDL_Quit();
	return 0;
}