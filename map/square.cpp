#include "square.h"

Square::Square() {
	this->x = 0;
	this->y = 0;
	this->state = '.';
}
Square::Square(int x, int y,
	Unit unit, Terrain terrain, Landmark landmark) {
	this->x = x;
	this->y = y;
	this->terrain = terrain;
	this->landmark = landmark;
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

char Square::getRepresentation() {
	return this->state;
}
