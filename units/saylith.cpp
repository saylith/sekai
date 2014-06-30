#include "saylith.h"

Saylith::Saylith() {
	this->setStats(2000, 10, 10, 10, 10, 4);
	this->setMOV(4);
	this->setWeapon(Unit::SWORD);
	this->setArmor(Unit::LIGHT);
	this->setType(Unit::FOOT);
	this->setGender(Unit::MALE);
	this->setStatus(Unit::NONE);
	this->setAce(true);
	this->representation = 's';
}

int Saylith::getAttackDamage(Unit enemy, Terrain terrain) {
	return 0;
}