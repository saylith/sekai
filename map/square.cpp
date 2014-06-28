#include "square.h"

Square::Square() {
	this->x = 0;
	this->y = 0;
}
Square::Square(int x, int y, 
	Unit unit, Terrain terrain, Landmark landmark) {
	this->x = x;
	this->y = y;
	this->terrain = terrain;
	this->landmark = landmark;
}
int Square::getX() {
	return this->x;
}
int Square::getY() {
	return this->y;
}
int Square::setX(int x) {
	return this->x = x;
}
int Square::setY(int y) {
	return this->y = y;
}
char Square::getRepresentation() {
	return 'o';
}