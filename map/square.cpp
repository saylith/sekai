/*
 * Square Object, which contains all data relevant to a single square on a battlemap object
 * including cooridnates, any terrain or landmark data, occupant (as the address of the occupant object), and the state of the square itself
 */

#include "square.h"

Square::Square() {//possible issues may arise from this, should we comment out or remove?
	this->coords.x = 0;
	this->coords.y = 0;
	this->state = NONE;
}
Square::Square(int x, int y,
	Terrain terrain, Landmark landmark, Unit *occupant) {
	this->coords.x = x;
	this->coords.y = y;
	this->terrain = terrain;
	this->landmark = landmark;
	this->occupant = occupant;
	this->state = NONE;
}
int Square::getX() {
	return this->coords.x;
}
int Square::getY() {
	return this->coords.y;
}
Square::Coords Square::getCoords() {
	return this->coords;
}
bool Square::isSelected() {
	return this->state == SELECTED;
}
bool Square::isHighlighted() {
	return this->state == HIGHLIGHTED;
}
int Square::setX(int x) {
	return this->coords.x = x;
}
int Square::setY(int y) {
	return this->coords.y = y;
}
Square::Coords Square::setCoords(Square::Coords coords) {
	return this->coords = coords;
}
char Square::setSelected() {
	return this->state = SELECTED;
}
char Square::setHighlighted() {
	return this->state = HIGHLIGHTED;
}
char Square::resetState() {
	return this->state = NONE;
}
char Square::setState(Square::State state) {
	return this->state = state;
}

bool Square::isOccupied() {
	return this->occupant != 0;
}

Unit *Square::getUnit() {
	return this->occupant;
}

Unit *Square::setUnit(Unit *unit) {
	return this->occupant = unit;
}

char Square::getRepresentation() {
	if(this->getUnit() != 0)
		return this->getUnit()->getRepresentation();
	return this->state;
}

Square::State Square::getState() {
	return this->state;
}
