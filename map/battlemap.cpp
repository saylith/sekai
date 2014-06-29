#include "battlemap.h"
#include <sstream>
#include <iostream>

BattleMap::BattleMap(){
	width = 0;
	height = 0;
	focus = NULL;
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
	focus = squares.front();
	focus->setFocused();
	squares.at(10)->setUnit(new Saylith());
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
	return squares.at(x*height + y);
}

Square* BattleMap::getSquareAt(Square::Coords coords) {
	return this->getSquareAt(coords.x, coords.y);
}

std::string BattleMap::printMap() {
	std::stringstream ss;
	std::string map;

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			ss << this->getSquareAt(x, y)->getRepresentation();
//            ss << "(" << x << "," << y << ") ";
		}
        ss << std::endl;
	}
	return ss.str();
}

Square *BattleMap::setFocus(int x, int y) {
	this->focus->resetState();
	this->focus = NULL;
	this->focus = getSquareAt(x, y);
	this->focus->setFocused();

	return this->focus;
}

Square *BattleMap::setFocus(Square::Coords coords) {
	return this->setFocus(coords.x, coords.y);
}

Square *BattleMap::moveFocus(Direction direction) {
	Square::Coords oldCoords = this->focus->getCoords();

	Square *ret = NULL;
	Square::Coords newCoords = 
		this->getValidCoordinatesInDirection(oldCoords, direction);
	ret = this->setFocus(newCoords);
	return ret;
}

Square *BattleMap::moveUnit(Direction direction) {
	Unit *unit = this->focus->getUnit();
	this->focus->setUnit(NULL);

	moveFocus(direction);

	this->focus->setUnit(unit);
	return this->focus;
}

Square::Coords BattleMap::getValidCoordinatesInDirection(
	Square::Coords coords, Direction direction) {
	switch(direction) {
		case EAST:
			// Right
			coords.x = std::min(coords.x + 1, this->width-1);
			break;
		case NORTH:
			// Up
			coords.y = std::max(coords.y - 1, 0);
			break;
		case WEST:
			// Left
			coords.x = std::max(coords.x - 1, 0);
			break;
		case SOUTH:
			// Down
			coords.y = std::min(coords.y + 1, this->height-1);
			break;
		default:
			break;
	}
	return coords;
}

Square *BattleMap::confirm() {
	if(this->focus->isOccupied()) {
		this->focus->setSelected();

	}
	return this->focus;
}



Square *BattleMap::cancel() {
	this->focus->setFocused();
	return this->focus;
}
