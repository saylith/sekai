/*
 * Generalized unit class: to be used as a parent for all other units
 */

#include "unit.h"

Unit::Stats Unit::getStats() {
    return this->stats;
}

/*
 * setStats Method should be used in initializing a unit.
 * Use setMOR, setGEN, setATK, setTEC, setLUK, setMOV when changing outside of initialization
 */
Unit::Stats Unit::setStats(
    int mor, int gen, int atk, int tec, int luk, int mov) {
    this->stats.MOR = mor;
    this->stats.GEN = gen;
    this->stats.ATK = atk;
    this->stats.TEC = tec;
    this->stats.LUK = luk;
    this->stats.MOV = mov;
    return this->stats;
}
int Unit::getMOR() {
    return this->stats.MOR;
}
int Unit::getGEN() {
    return this->stats.GEN;
}
int Unit::getATK() {
    return this->stats.ATK;
}
int Unit::getTEC() {
    return this->stats.TEC;
}
int Unit::getLUK() {
    return this->stats.LUK;
}
int Unit::getMOV() {
    return this->stats.MOV;
}
int Unit::setMOR(int mor) {
    return this->stats.MOR = mor;
}
int Unit::setGEN(int gen) {
    return this->stats.GEN = gen;
}
int Unit::setATK(int atk) {
    return this->stats.ATK = atk;
}
int Unit::setTEC(int tec) {
    return this->stats.TEC = tec;
}
int Unit::setLUK(int luk) {
    return this->stats.LUK = luk;
}
int Unit::setMOV(int mov) {
    return this->stats.MOV = mov;
}

Unit::Weapon Unit::getWeapon() {
    return this->weapon;
}
Unit::Weapon Unit::setWeapon(Weapon weapon) {
    return this->weapon = weapon;
}
bool Unit::isMelee() {
    switch(this->weapon) {
        case Unit::SWORD:
            return true;
            break;
        case Unit::AXE:
            return true;
            break;
        case Unit::LANCE:
            return true;
            break;
        default:
            return false;
            break;
    }
}
bool Unit::isRanged() {
    switch(this->weapon) {
        case Unit::BOW:
            return true;
            break;
        case Unit::CROSSBOW:
            return true;
            break;
        case Unit::GUN:
            return true;
            break;    
        default:
            return false;
            break;
    }
}
bool Unit::isMagic(){
    switch(this->weapon) {
        case Unit::WAND:
            return true;
            break;
        case Unit::STAFF:
            return true;
            break;
        case Unit::TOME:
            return true;
            break;    
        default:
            return false;
            break;
    }
}
Unit::Armor Unit::getArmor() {
    return this->armor;
}
Unit::Armor Unit::setArmor(Unit::Armor) {
    return this->armor = armor;
}
Unit::Type Unit::getType() {
    return this->type;
}
Unit::Type Unit::setType(Unit::Type type) {
    return this->type = type;
}
Unit::Gender Unit::getGender() {
    return this->gender;
}
Unit::Gender Unit::setGender(Unit::Gender gender) {
    return this->gender = gender;
}
Unit::Status Unit::getStatus() {
    return this->status;
}
Unit::Status Unit::setStatus(Unit::Status status) {
    return this->status = status;
}
bool Unit::isAce() {
    return this->ace;
}
bool Unit::setAce(bool ace) {
    return this->ace = ace;
}

int Unit::getAttackDamage(Unit enemy, Terrain terrain)
{
    return 0;
}

int Unit::getMovement()
{
    return this->getMOV();
}
char Unit::getRepresentation()
{
    return representation;
}
