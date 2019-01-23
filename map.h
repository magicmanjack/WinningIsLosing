#include <SDL.h>
#include <vector>
#include "obstacle.h"

class Map {
	public:
		std::vector<Obstacle *> obstacles;
		static Map * loadMapOne(SDL_Renderer * r);
		static Map * loadMapTwo(SDL_Renderer * r);
		static Map * loadMapThree(SDL_Renderer * r);
		bool collision(SDL_Rect rect);
		void drawMap(SDL_Renderer * r, int offsetX, int offsetY);
};