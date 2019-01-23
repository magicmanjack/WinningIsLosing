#include <SDL.h>
#include "map.h"
#include "obstacle.h"

Map * Map::loadMapOne(SDL_Renderer * r) {
	Map * map = new Map();
	map -> obstacles.push_back(new Obstacle(r, 350, 500));
	map -> obstacles.push_back(new Obstacle(r, 700, 0));
	return map;
}

Map * Map::loadMapTwo(SDL_Renderer * r) {
	
}

Map * Map::loadMapThree(SDL_Renderer * r) {
	
}

bool Map::collision(SDL_Rect rect) {
	bool collides = false;
	for(int i = 0; i < obstacles.size(); i++) {
		SDL_Rect oRect = obstacles[i] -> rect;
		if(rect.x + rect.w >= oRect.x && rect.x <= oRect.x + oRect.w
		&& rect.y + rect.h >= oRect.y && rect.y <= oRect.y + oRect.h) {
			collides = true;
			obstacles[i] -> flare = true;
		}
	}
	return collides;
}

void Map::drawMap(SDL_Renderer * r, int offsetX, int offsetY) {
	for(int i = 0; i < obstacles.size(); i++) {
		obstacles[i] -> draw(r, offsetX, offsetY);	
	}
}