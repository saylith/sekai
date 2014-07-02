#ifndef TERRAIN_H
#define TERRAIN_H

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

	class TerrainSpriteManager {
	private:
		sf::Texture texture;

		sf::Sprite *oneBlock;
		sf::Sprite *twoBlock;
		sf::Sprite *topBlock;
	public:
		TerrainSpriteManager();
		TerrainSpriteManager(TerrainType tt);

	};

	Terrain();
	Terrain(TerrainType tt);
private:

	TerrainType terrainType;
};
#endif