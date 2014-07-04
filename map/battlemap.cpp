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
	this->state = std::vector<BattleMap::State>(40, BattleMap::NONE);
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

BattleMap::State BattleMap::setStateAt(int x, int y, BattleMap::State state) {
	return this->state.at(x*height + y) = state;
}

BattleMap::State BattleMap::setStateAt(BattleMap::Coords coords, BattleMap::State state) {
	return this->setStateAt(coords.x, coords.y, state);
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

BattleMap::Coords BattleMap::movePath(Direction direction) {
	BattleMap::Coords newCoords = 
		this->getValidCoordsInDirection(this->focus, direction);


	if(getStateAt(newCoords) == BattleMap::ACCESSIBLE
		|| getStateAt(newCoords) == BattleMap::REACHABLE
		|| getStateAt(newCoords) == BattleMap::PATH) {

		path.directions.push_back(direction);

		for(BattleMap::Direction dir : path.directions)
			std::cout << dir;
		std::cout << std::endl;

		moveFocus(direction);
	}
		
}

BattleMap::Coords BattleMap::moveUnit() {
	Unit *unit = getSquareAt(path.origin)->getUnit();
	getSquareAt(path.origin)->setUnit(NULL);

	if(getStateAt(focus) == BattleMap::REACHABLE)
		path.directions.pop_back();

	Coords destination = path.origin;
	for(BattleMap::Direction dir : path.directions)
		destination = getValidCoordsInDirection(destination, dir);
	getSquareAt(destination)->setUnit(unit);
	return destination;
}

std::string BattleMap::printMap() {
	std::stringstream ss;
	std::string map;

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {

			// Focus > Unit > State
			if(this->focus.x == x && this->focus.y == y)
				ss << "f";	
			else if(getSquareAt(x, y)->isOccupied())
				ss << 'u';
			else
				ss << (char) this->getStateAt(x, y);		
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

				// Translate from grid coords to view coords
				int pixelX = x*50 - y*50;
				int pixelY = y*30 + x*30;
				sprite.move(pixelX, pixelY);

				// Set the color of the sprite based on focus/state
				if(this->focus.x == x && this->focus.y == y) 
					sprite.setColor(sf::Color(255,153,0));

				else switch(getStateAt(x,y)) {
						case ACCESSIBLE:
							sprite.setColor(sf::Color(51, 102, 153));
							break;
						case REACHABLE:
							sprite.setColor(sf::Color(255, 0, 0));
							break;
						default:
							break;
					}
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
	return coords;
}

void BattleMap::updateStateOnSelection() {
	Coords selection = this->focus;
	if(!getSquareAt(selection)->isOccupied()) 
		return;

	path.origin = focus;
	path.max = getSquareAt(focus)->getUnit()->getMovement();

	Unit *unit = getSquareAt(selection)->getUnit();

	int radius = unit->getMovement() + 1;
	setRadiusState(selection, radius + 1, BattleMap::REACHABLE);
	setRadiusState(selection, radius, BattleMap::ACCESSIBLE);
}

void BattleMap::setRadiusState(Coords selection, int radius, BattleMap::State state) {
	if (radius == 0)
		return;

	setStateAt(selection, state);

	for(BattleMap::Direction dir : {BattleMap::NORTH, BattleMap::SOUTH, BattleMap::WEST, BattleMap::EAST}) {
		BattleMap::Coords newCoord = getValidCoordsInDirection(selection, dir);
		setRadiusState(newCoord, radius -1, state);		
	}
}

void BattleMap::clearState() {
	this->state = std::vector<BattleMap::State>(
		this->width * this->height, BattleMap::NONE);
	path.origin = focus;
	path.directions.clear();
	path.max = 0;
}

void BattleMap::setFocusToOrigin() {
	focus = path.origin;
}

void BattleMap::setUnitDirection(BattleMap::Direction direction) {
	Unit *unit = getSquareAt(focus)->getUnit();
	unit->setDirection( (Unit::Direction)(char)direction);
}