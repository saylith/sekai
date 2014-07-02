#include "terrain.h"

std::map<Terrain::TerrainType, sf::Texture*> Terrain::textureStore;

Terrain::Terrain() {
	terrainType = Terrain::NONE;
}

Terrain::Terrain(TerrainType tt) {
	terrainType = tt;
}

sf::Sprite Terrain::getSprite(int x, int y, int h, TerrainType tt) {
	sf::Texture *texture;

	if( Terrain::textureStore.count(tt) <= 0 ) {
		std::string filename = "map/terrain_sprites/generic.png";

		switch(tt) {
			case Terrain::GRASS:
				filename = "map/terrain_sprites/grass.png";
				break;
			default:
				break;
		}
		sf::Image image;
	    image.loadFromFile(filename);
	    image.createMaskFromColor(sf::Color(0,255,0,255));

		sf::Texture *texture = new sf::Texture();
	    texture->loadFromImage(image, sf::IntRect(0,0,438,144));
	    Terrain::textureStore.insert(std::make_pair(tt, texture));
	}
	else {
		texture = Terrain::textureStore.at(tt);
	}


	
	sf::Sprite sprite;
	sprite.setTexture(*texture);
	sprite.setPosition(x*50 - y*50, y*30 + x*30);
	switch(h) {
		case 1:
			sprite.setTextureRect(sf::IntRect(0, 0, 144, 144));	
			break;
		case 2:
			sprite.setTextureRect(sf::IntRect(144, 0, 144, 144));	
			break;
		default:
			sprite.setTextureRect(sf::IntRect(288, 0, 144, 144));	
			sprite.move(sf::Vector2f(0, -10));
			break;
	}
	
	return sprite;
}