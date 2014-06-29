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
	squares.at(10)->setUnit(new Saylith());
	squares.at(36)->setUnit(new Saylith());
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

Square *BattleMap::getFocus() {
	return this->focus;
}

std::string BattleMap::printMap() {
	std::stringstream ss;
	std::string map;

	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			if(this->focus->coords.x == x && this->focus->coords.y == y)
				ss << "f";
			else
				ss << this->getSquareAt(x, y)->getRepresentation();
//            ss << "(" << x << "," << y << ") ";
		}
        ss << std::endl;
	}
	return ss.str();
}

Square *BattleMap::setFocus(int x, int y) {
	this->focus = getSquareAt(x, y);

	return this->focus;
}

Square *BattleMap::setFocus(Square::Coords coords) {
	return this->setFocus(coords.x, coords.y);
}

Square *BattleMap::moveFocus(Direction direction) {
	Square::Coords oldCoords = this->focus->getCoords();

	Square *ret = NULL;
	Square::Coords newCoords = 
		this->getValidCoordsInDirection(oldCoords, direction);
	ret = this->setFocus(newCoords);
	return ret;
}

Square *BattleMap::moveUnit(Square::Coords source, Square::Coords dest) {
	Unit *unit = getSquareAt(source)->getUnit();
	getSquareAt(source)->setUnit(NULL);
	getSquareAt(dest)->setUnit(unit);
	return getSquareAt(dest);
}

Square *BattleMap::movePath(Direction direction) {

	Square::Coords dest = getValidCoordsInDirection(this->focus->coords,
	 direction, this->focus->getUnit());

	Square::State state = this->getSquareAt(dest)->getState();

	if(state == Square::HIGHLIGHTED || state == Square::PATH) {

		moveFocus(direction);

		this->focus->setState(Square::PATH);
		this->path.push_back(this->focus);

	}
	return this->focus;
}

Square::Coords BattleMap::getValidCoordsInDirection(
	Square::Coords coords, Direction direction, Unit *myUnit) {
	Square::Coords oldCoords = coords;
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

void BattleMap::calculatePossibleMoves(Square *selection) {
	if(!selection->isOccupied())
		return;

	int remaining = selection->getUnit()->getMovement();
	possibleMoves = std::vector<Square *>();
	calculatePossibleMoves(selection, selection->getUnit(), remaining+1);

	for(int i = 0; i < possibleMoves.size(); i++) {
		possibleMoves.at(i)->setHighlighted();
	}
}

void BattleMap::calculatePossibleMoves(Square *selection, Unit *myUnit,
		int remaining) {
	if(remaining == 0)
		return;
	if(selection->isOccupied() && selection->getUnit() != myUnit)
		return;

	possibleMoves.push_back(selection);

	Square::Coords northCoords = getValidCoordsInDirection(
		selection->getCoords(), BattleMap::NORTH);
	Square::Coords southCoords = getValidCoordsInDirection(
		selection->getCoords(), BattleMap::SOUTH);
	Square::Coords eastCoords = getValidCoordsInDirection(
		selection->getCoords(), BattleMap::EAST);
	Square::Coords westCoords = getValidCoordsInDirection(
		selection->getCoords(), BattleMap::WEST);

	calculatePossibleMoves(
		this->getSquareAt(northCoords), myUnit, remaining -1);
	calculatePossibleMoves(
		this->getSquareAt(southCoords), myUnit, remaining -1);
	calculatePossibleMoves(
		this->getSquareAt(westCoords), myUnit, remaining -1);
	calculatePossibleMoves(
		this->getSquareAt(eastCoords), myUnit, remaining -1);

}

void BattleMap::clearPossibleMoves() {
	for(int i = 0; i < possibleMoves.size(); i++) {
		possibleMoves.at(i)->resetState();
	}
	possibleMoves.clear();
}


void BattleMap::clearPath() {
	for(int i = 0; i < path.size(); i++) {
		path.at(i)->resetState();
	}
	path.clear();
}

Square *BattleMap::confirm() {
	if(this->focus->isOccupied()) {
		this->focus->setSelected();

	}
	return this->focus;
}



Square *BattleMap::cancel() {
	clearPossibleMoves();
	clearPath();
	return this->focus;
}

void BattleMap::confirmUnitSelection() {
	if(this->focus->isOccupied()) {
		this->focus->setSelected();
	}
	this->calculatePossibleMoves(this->focus);
	path.push_back(this->focus);
}

void BattleMap::confirmUnitDestination() {
	path.push_back(this->focus);
}	

void BattleMap::confirmUnitWait() {
	moveUnit(path.front()->getCoords(), path.back()->getCoords());
	clearPath();
	clearPossibleMoves();
}

void BattleMap::cancelUnitSelection() {
	this->focus = path.front();
	clearPath();
	clearPossibleMoves();
}

void BattleMap::cancelUnitMenu() {

}