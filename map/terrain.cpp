#include "terrain.h"

Terrain::TerrainManager() {

}

Terrain::TerrainManager(Terrain::TerrainType tt) {
	this->loadSprite(tt);
}

void Terrain::TerrainManager::loadSprite(Terrain::TerrainType tt) {
		std::string filename = "terrain_sprites/generic.png";

		switch(this->terrainType) {
			case GRASS:
				filename = "terrain_sprites/grass.png";
				break;
			default:
				break;
		}

	    sf::Image image;
        image.loadFromFile(filename);
        image.createMaskFromColor(sf::Color(0,255,0,255));

        sf::Texture texture;
        texture.loadFromImage(image);

        oneBlock.setTexture(texture, sf::IntRect(0, 0, 144, 144));
        twoBlock.setTexture(texture, sf::IntRect(144, 0, 144, 144));
        topBlock.setTexture(texture, sf::IntRect(288, 0, 144, 144));
}