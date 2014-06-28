#include "battlemap.h"
#include <sstream>
#include <iostream>

BattleMap::BattleMap(){
	width = 0;
	height = 0;
}

BattleMap::BattleMap(int width, int height){
	this->width = width;
	this->height = height;
	for(int x = 0; x < width; x++) {
		for(int y = 0; y < height; y++) {
			Square *square = new Square(x, y);
			squares.push_back(square);
		}
	}
}

int BattleMap::getWidth() {
	return this->width;
}
int BattleMap::getHeight() {
	return this->height;
}

int BattleMap::setWidth(int width) {
	return this->width = width;
}
int BattleMap::setHeight(int height) {
	return this->height = height;
}

Square* BattleMap::getSquareAt(int x, int y) {
	return squares.at(x + width*y);
}

std::string BattleMap::printMap() {
	std::stringstream ss;
	std::string map;

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			ss << this->getSquareAt(x, y)->getRepresentation();
		}
		ss << std::endl;
	}
	return ss.str();
}

int main() {
	BattleMap map(30,10);
	std::cout << map.printMap();
}