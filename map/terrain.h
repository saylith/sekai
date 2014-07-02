#ifndef TERRAIN_H
#define TERRAIN_H

#include <SFML/Graphics.hpp>

class Terrain
{
public:
	
	enum TerrainType {
		GRASS,
		ROAD,
		TOWN,
		CITY,
		FORT,
		CASTLE,
		WATER,
		WILDERNESS,
		MOUNTAIN,
		SKY,
		NONE
	};

	Terrain();
	Terrain(TerrainType tt);

	sf::Sprite getSprite(int x, int y, int z);
private:
	TerrainType terrainType;
};
#endif