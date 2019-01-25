#include <SDL.h>
#include "map.h"
#include "obstacle.h"

int Map::scrBoundsW = 800;
int Map::scrBoundsH = 600;

Map::~Map() {
	for(std::vector<Obstacle *>::iterator pObj = obstacles.begin(); pObj != obstacles.end(); pObj++) {
		delete *pObj;
	}
	for(std::vector<Enemy *>::iterator pObj = enemies.begin(); pObj != enemies.end(); pObj++) {
		delete *pObj;
	}
	SDL_Log("DELETED MAP");
}

Map * Map::loadMapOne(SDL_Renderer * r) {
	Map * map = new Map();
	map -> spawnX = 350;
	map -> spawnY = 250;
	map -> obstacles.push_back(new Obstacle(r, 350, 400, "res\\floor.bmp"));
	map -> obstacles.push_back(new Obstacle(r, 700, 0, "res\\roof.bmp"));
	Obstacle * cb = new Obstacle(r, 800, 250, "res\\cube.bmp");
	cb -> rect.h = 100;
	map -> obstacles.push_back(cb);
	map -> enemies.push_back(new Enemy(0, 100, r));
	map -> enemies.push_back(new Enemy(0, 200, r));
	map -> enemies.push_back(new Enemy(500, 300, r));
	return map;
}

Map * Map::loadMapTwo(SDL_Renderer * r) {
	
}

Map * Map::loadMapThree(SDL_Renderer * r) {
	
}

void Map::update() {
	Enemy::target = plyr -> rect;
	for(int i = 0; i < enemies.size(); i++) {
		enemies[i] -> update();
	}
	std::vector<int> toRemove;
	for(int i = 0; i < enemies.size(); i++) {
		bool removed;
		for(int j = 0; j < enemies.size(); j++) {
			if(collision(enemies[i] -> rect, enemies[j] -> rect)  && i != j) {
				toRemove.push_back(i);
				removed = true;
			}
		}
		if(!removed && collision(enemies[i] -> rect, plyr -> rect)) {
			toRemove.push_back(i);
			plyr -> dead = true;
		}
	}
	while(toRemove.size() > 0) {
		delete enemies[toRemove[toRemove.size() - 1]];
		enemies.erase(enemies.begin() + toRemove[toRemove.size() - 1]);
		toRemove.erase(toRemove.begin() + toRemove.size() - 1);
	}
	for(int i = 0; i < obstacles.size(); i++) {
		if(collision(plyr -> rect, obstacles[i] -> rect)) {
			obstacles[i] -> flare = true;
			plyr -> dead = true;
		}
	}
}

bool Map::collision(SDL_Rect rA, SDL_Rect rB) {
	if(rA.x + rA.w >= rB.x && rA.x <= rB.x + rB.w
		&& rA.y + rA.h >= rB.y && rA.y <= rB.y + rB.h) {
		return true;
	}
	return false;
}

void Map::drawMap(SDL_Renderer * r, int offsetX, int offsetY) {
	for(int i = 0; i < obstacles.size(); i++) {
		obstacles[i] -> draw(r, offsetX, offsetY);	
	}
	for(int i =  0; i < enemies.size(); i++) {
		enemies[i] -> draw(r, offsetX, offsetY);
	}
}