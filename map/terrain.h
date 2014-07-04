#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
	int z;
	double cost;
	char representation;

public:
	enum IsStair {
		NONE = 0,
		NW = 1,
		NE = 2
	};

private:
	IsStair isStair;

public:

	//constructors
	Terrain();

	Terrain(int z = 0,
			double cost = 1.0,
			IsStair isStair = 0,
			char representation = '.');

	//accessor methods
	int getZ();
	double getCost();
	char getRepresentation();
	IsStair getStair();

	//mutator methods
	int setZ(int z);
	double setCost(double cost);
	//char setRepresentation(char representation);//shouldn't need this
	IsStair setStair(IsStair isStair);

};
#endif