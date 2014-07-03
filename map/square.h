#ifndef SQUARE_H
#define SQUARE_H

#include "../units/unit.h"
#include "../units/saylith.h"
#include <SFML/Graphics.hpp>

class Square
{
	
public:
	enum Terrain {
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
	static std::map<Terrain, sf::Texture*> textureStore;

	enum Landmark {
		EMPTY
	};

	Square(
		Unit *occupant = 0,
		Terrain terrain = NONE, 
		Landmark landmark = EMPTY,
		int height = 1
	);

	Unit *getUnit();
	Unit *setUnit(Unit *unit);
	bool isOccupied();

	Terrain getTerrain();
	Terrain setTerrain(Terrain terrain);

	char getRepresentation();
	std::vector<sf::Sprite> getSprites();

private:
	Unit *occupant;
	Terrain terrain;
	Landmark landmark;
	int height;
};

#endif