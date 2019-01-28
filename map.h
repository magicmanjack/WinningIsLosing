#include <SDL.h>
#include <vector>
#include "obstacle.h"
#include "enemy.h"
#include "player.h"
#include "finishLine.h"

class Map {
	public:
		static int scrBoundsW, scrBoundsH;
		std::vector<Obstacle *> obstacles;
		std::vector<Enemy *> enemies;
		FinishLine * finish;
		Player * plyr;
		static Map * loadMapOne(SDL_Renderer * r);
		static Map * loadMapTwo(SDL_Renderer * r);
		static Map * loadMapThree(SDL_Renderer * r);
		static Map * loadMap(int i, SDL_Renderer * r);
		bool collision(SDL_Rect rA, SDL_Rect rB);
		void update();
		void drawMap(SDL_Renderer * r, int offsetX, int offsetY);
		int spawnX, spawnY;
		~Map();
};