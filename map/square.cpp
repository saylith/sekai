/*
 * Square Object, which contains all data relevant to a single square on a battlemap object
 * including cooridnates, any terrain or landmark data, occupant (as the address of the occupant object), and the state of the square itself
 */
#include "square.h"
 #include <iostream>
std::map<Square::Terrain, sf::Texture*> Square::textureStore;


Square::Square(Unit *occupant, Terrain terrain, Landmark landmark,
	int height) {
	this->occupant = occupant;
	this->terrain = terrain;
	this->landmark = landmark;
	this->height = height;
}

Unit *Square::getUnit() {
	return this->occupant;
}

Unit *Square::setUnit(Unit *unit) {
	return this->occupant = unit;
}

bool Square::isOccupied() {
	return this->occupant != 0;
}

Square::Terrain Square::getTerrain() {
	return this->terrain;
}

Square::Terrain Square::setTerrain(Terrain terrain) {
	return this->terrain = terrain;
}

Square::Landmark Square::getLandmark() {
	return this->landmark;
}

Square::Landmark Square::setLandmark(Landmark landmark) {
	return this->landmark = landmark;
}

int Square::getHeight() {
	return this->height;
}

int Square::setHeight(int height) {
	return this->height = height;
}

char Square::getRepresentation() {
	if(this->getUnit() != 0)
		return this->getUnit()->getRepresentation();
	return '.';
}

std::vector<sf::Sprite> Square::getSprites() {

	// Load texture if not already cached
	sf::Texture *texture;
	if( Square::textureStore.count(this->terrain) <= 0 ) {
		std::string filename = "map/terrain_sprites/generic.png";

		switch(this->terrain) {
			case Square::GRASS:
				filename = "map/terrain_sprites/grass.png";
				break;
			default:
				break;
		}
		sf::Image image;
	    image.loadFromFile(filename);
	    image.createMaskFromColor(sf::Color(0,255,0,255));

		sf::Texture *tex = new sf::Texture();
	    tex->loadFromImage(image);
	    Square::textureStore.insert(std::make_pair(this->terrain, tex));
	}
	texture = Square::textureStore.at(this->terrain);
	

	// // Setup sprites
	sf::Sprite top;
	sf::Sprite oneBlock;
	sf::Sprite twoBlock;

	top.setTexture(*texture, true);
	oneBlock.setTexture(*texture);
	twoBlock.setTexture(*texture);

	top.setTextureRect(sf::IntRect(288, 0, 144, 144));	
	oneBlock.setTextureRect(sf::IntRect(0, 0, 144, 144));	
	twoBlock.setTextureRect(sf::IntRect(144, 0, 144, 144));	

	std::vector<sf::Sprite> sprites;
	
	for(int i = 0; i < this->height-1; i+=2) {
		sf::Sprite copyBlock = twoBlock;
		copyBlock.move(0, -20*i);
		//copyBlock.setColor(sf::Color(139, 139, 139)); //uncomment to make more visible
		sprites.push_back(copyBlock);
	}

	if(this->height % 2 == 1) {
		oneBlock.move(0, -20 * (this->height - 1));
		sprites.push_back(oneBlock);
	}
	top.move(0, -20 * (this->height));
	sprites.push_back(top);
	return sprites;
}