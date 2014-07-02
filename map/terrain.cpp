#include "terrain.h"

Terrain::Terrain() {
	terrainType = Terrain::NONE;
}

Terrain::Terrain(TerrainType tt) {
	terrainType = tt;
}

sf::Sprite Terrain::getSprite(int x, int y, int z) {
	std::string filename = "map/terrain_sprites/generic.png";

	switch(this->terrainType) {
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
	
	sf::Sprite sprite;
	sprite.setTexture(*texture);
	sprite.setPosition(x*50 + y*50, -y*30 + x*30);
	switch(z) {
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