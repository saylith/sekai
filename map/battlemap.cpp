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

Square *BattleMap::moveFocus(int direction) {
	int currentX = this->focus->getX();
	int currentY = this->focus->getY();
	int newX = currentX, newY = currentY;
	Square *ret = NULL;
	switch(direction) {
		case 0:
			// Right
			newX = std::min(currentX + 1, this->width-1);
			break;
		case 1:
			// Up
			newY = std::max(currentY - 1, 0);
			break;
		case 2:
			// Left
			newX = std::max(currentX - 1, 0);
			break;
		case 3:
			// Down
			newY = std::min(currentY + 1, this->height-1);
			break;
		default:
			break;
	}
	ret = this->setFocus(newX, newY);
	return ret;
}

Square *BattleMap::confirm() {
	this->focus->setSelected();
	return this->focus;
}

Square *BattleMap::cancel() {
	this->focus->setFocused();
	return this->focus;
}
