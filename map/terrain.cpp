/* Generalized Terrain class, to be used as a parent for all terrain types
 * The terrain class contains all information relevant to the terrain of a square TODO: Add z-movement attribute to unit class
 * 		Z: A Z level (travel should be limited to 1 z level by default)
 * 		Stair: : A stair property (NONE, NW, NE, SW, SE) permits travel up any number of levels for foot type units
 * 			(does not need to be specified, should just universally permit movement in that direction)
 * 		Cost: A Movement Penalty: Number to be removed from the unit's available movement when the unit moves INTO the square
 * 		Representation: a way of representing the tile (char or image file or what have you)
 */
#include "terrain.h"

Terrain::Terrain() {
	int z = 0;
	IsStair isStair = 0;
	double cost = 1.0;
	char representation = '.';
}

Terrain::Terrain(int z, double cost, IsStair isStair, char representation) {
	this->z = z;
	this->cost = cost;
	this->isStair = isStair;
	this->representation = representation;
}

int Terrain::getZ()
{
	return this->z;
}

double Terrain::getCost()
{
	return this->cost;
}

char Terrain::getRepresentation()
{
	return this->representation;
}

Terrain::IsStair Terrain::getStair()
{
	return this->isStair;
}

int Terrain::setZ(int z)
{
	return this->z = z;
}

double Terrain::setCost(double cost)
{
	return this->cost = cost;
}

/*char Terrain::setRepresentation(char representation)//shouldn't need this
{
	return this->representation = representation;
}*/

Terrain::IsStair Terrain::setStair(Terrain::IsStair stair)
{
	return this->isStair = stair;
}
