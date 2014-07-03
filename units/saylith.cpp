/*
 * Basic testing unit with the following attributes:
 * 2000 morale, 10 general, 11 attack, 12 technique, 13 luck, 4 movement
 * Weapon: Sword, Armor: Light, Type: footsoldier, Male, Ace
 * represented by 's'
 */
#include "saylith.h"

Saylith::Saylith() {
	this->setStats(2000, 10, 11, 12, 13, 3);
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
