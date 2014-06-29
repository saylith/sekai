#include "square.h"

Square::Square() {
	this->x = 0;
	this->y = 0;
	this->state = '.';
}
Square::Square(int x, int y,
	Terrain terrain, Landmark landmark, Unit *occupant) {
	this->x = x;
	this->y = y;
	this->terrain = terrain;
	this->landmark = landmark;
	this->occupant = occupant;
	this->state = '.';
}
int Square::getX() {
	return this->x;
}
int Square::getY() {
	return this->y;
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
	return this->x = x;
}
int Square::setY(int y) {
	return this->y = y;
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
		return 'o';
	return this->state;
}
