/*
 * Object which holds data relevant to the map upon which a battle takes place
 * does this by creating a vector of Square objects
 * Coordinates in the grid are defined as x*height + y (which seems wrong to me, Saylith, can you sketch a visualization of this  perhaps?)
 *
 * Currently defaults to placing two "Saylith" units at positions 10 and 36
 */

#include "battlemap.h"
#include <sstream>
#include <iostream>

BattleMap::BattleMap(int width, int height){ 
	this->width = width;
	this->height = height;
	focus.x = 0;
	focus.y = 0;
}

BattleMap::BattleMap(bool testing) {
	this->width = 4;
	this->height = 10;
	for(int x = 0; x < width; x++) {
		for(int y = 0; y < height; y++) {
			Square *square = new Square();
			squares.push_back(square);
		}
	}
	focus.x = 0;
	focus.y = 0;
	squares.at(10)->setUnit(new Saylith());
	squares.at(36)->setUnit(new Saylith());

	squares.at(0)->setHeight(7);
	squares.at(1)->setHeight(6);
	squares.at(2)->setHeight(5);
	squares.at(3)->setHeight(4);
	squares.at(36)->setHeight(3);
	squares.at(37)->setHeight(2);
	squares.at(38)->setHeight(1);
	squares.at(39)->setHeight(0);
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

Square* BattleMap::getSquareAt(BattleMap::Coords coords) {
	return this->getSquareAt(coords.x, coords.y);
}

BattleMap::State BattleMap::getStateAt(int x, int y) {
	return state.at(x*height + y);
}

BattleMap::State BattleMap::getStateAt(BattleMap::Coords coords) {
	return this->getStateAt(coords.x, coords.y);
}

BattleMap::State BattleMap::setStateAt(BattleMap::State state, int x, int y) {
	return this->state.at(x*height + y) = state;
}

BattleMap::State BattleMap::setStateAt(BattleMap::State state, BattleMap::Coords coords) {
	return this->setStateAt(state, coords.x, coords.y);
}

BattleMap::Coords BattleMap::getFocus() {
	return this->focus;
}

BattleMap::Coords BattleMap::setFocus(int x, int y) {
	this->focus.x = x;
	this->focus.y = y;

	return this->focus;
}

BattleMap::Coords BattleMap::setFocus(BattleMap::Coords coords) {
	return this->setFocus(coords.x, coords.y);
}

BattleMap::Coords BattleMap::moveFocus(Direction direction) {
	BattleMap::Coords oldCoords = this->focus;

	BattleMap::Coords newCoords = 
		this->getValidCoordsInDirection(oldCoords, direction);
	return this->setFocus(newCoords);
}

BattleMap::Coords BattleMap::moveUnit(BattleMap::Coords source, BattleMap::Coords dest) {
	if(getSquareAt(source)->getUnit() == NULL) {
		Unit *unit = getSquareAt(source)->getUnit();
		getSquareAt(source)->setUnit(NULL);
		getSquareAt(dest)->setUnit(unit);
		return dest;
	}
	return source;
}

std::string BattleMap::printMap() {
	std::stringstream ss;
	std::string map;

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			if(this->focus.x == x && this->focus.y == y)
				ss << "f";
			
			else
				ss << this->getSquareAt(x, y)->getRepresentation();
		}
        ss << std::endl;
	}
	return ss.str();
}

std::vector<sf::Sprite> BattleMap::getSprites() {
	std::vector<sf::Sprite> sprites;
	for (int y = 0; y < this->height; y++)
		for(int x = 0; x < this->width; x++) {
			Square *square = this->getSquareAt(x, y);
			for(sf::Sprite sprite : square->getSprites()) {
					int pixelX = x*50 - y*50;
					int pixelY = y*30 + x*30;
					sprite.move(pixelX, pixelY);
	// block.setPosition(pixelX, pixelY);
				if(this->focus.x == x && this->focus.y == y) 
					sprite.setColor(sf::Color(255,153,0));
				
				sprites.push_back(sprite);
			}
		}

	return sprites;
}

BattleMap::Coords BattleMap::getValidCoordsInDirection(
	BattleMap::Coords coords, Direction direction, Unit *myUnit) {
	BattleMap::Coords oldCoords = coords;
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
	//if(getSquareAt(coords)->isOccupied() && myUnit != NULL &&
	//	getSquareAt(coords)->getUnit() != myUnit)
	//	return oldCoords;
	return coords;
}

void BattleMap::updateStateOnSelection(Coords selection) {
	// if(!getSquareAt(selection)->isOccupied()) 
	// 	return;

	// int remaining = getSquareAt(selection)->getUnit()->getMovement();
	// possibleMoves = std::vector<Coords>();
	// calculatePossibleMoves(selection, getSquareAt(selection)->getUnit(), remaining+1);
}

void BattleMap::calculateAccessibleSquares(Coords selection, Unit *myUnit,
		int remaining) {
	// if(remaining == 0)
	// 	return;
	// if(getSquareAt(selection)->isOccupied() && getSquareAt(selection)->getUnit() != myUnit)
	// 	return;

	// possibleMoves.push_back(selection);

	// BattleMap::Coords northCoords = getValidCoordsInDirection(
	// 	selection, BattleMap::NORTH);
	// BattleMap::Coords southCoords = getValidCoordsInDirection(
	// 	selection, BattleMap::SOUTH);
	// BattleMap::Coords eastCoords = getValidCoordsInDirection(
	// 	selection, BattleMap::EAST);
	// BattleMap::Coords westCoords = getValidCoordsInDirection(
	// 	selection, BattleMap::WEST);

	// calculateAccessibleSquares(
	// 	northCoords, myUnit, remaining -1);
	// calculateAccessibleSquares(
	// 	southCoords, myUnit, remaining -1);
	// calculateAccessibleSquares(
	// 	westCoords, myUnit, remaining -1);
	// calculateAccessibleSquares(
	// 	eastCoords, myUnit, remaining -1);

}

void BattleMap::calculateReachableSquares(
	std::vector<BattleMap::Coords> reachable) {

}

void BattleMap::clearAccessible() {
	
}

void BattleMap::clearReachable() {
	
}

void BattleMap::clearPaths() {
	
}

void BattleMap::clearState() {

}