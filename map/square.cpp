#include "square.h"

Square::Square() {
	this->coords.x = 0;
	this->coords.y = 0;
	this->state = '.';
}
Square::Square(int x, int y,
	Terrain terrain, Landmark landmark, Unit *occupant) {
	this->coords.x = x;
	this->coords.y = y;
	this->terrain = terrain;
	this->landmark = landmark;
	this->occupant = occupant;
	this->state = '.';
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
bool Square::isFocused() {
	return this->state == 'f';
}
bool Square::isSelected() {
	return this->state == 's';
}
bool Square::isHighlighted() {
	return this->state == 'h';
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
char Square::setFocused() {
	return this->state = 'f';
}
char Square::setSelected() {
	return this->state = 's';
}
char Square::setHighlighted() {
	return this->state = 'h';
}
char Square::resetState() {
	return this->state = '.';
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
