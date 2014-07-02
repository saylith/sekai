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
	static std::map<TerrainType, sf::Texture*> textureStore;
	static sf::Sprite getSprite(int x, int y, int h, TerrainType tt);

private:
	TerrainType terrainType;
};


#endif

