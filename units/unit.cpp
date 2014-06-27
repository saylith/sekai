#include "unit.h"


int Unit::getAttackDamage(Unit enemy, Terrain terrain);

int Unit::getMovement()
{
    return movement;
}
int Unit::getAttack()
{
    return attack;
} 
int Unit::getHp()
{
    return hp;
}
int Unit::getMaxHp()
{
    return maxHp;
}
int Unit::getMp()
{
    return mp;
}
int Unit::getMaxMp()
{
    return maxMp;
}
int Unit::getActions()
{
    return actions;
}
char Unit::getRepresentation()
{
    return representation;
}
WeaponType Unit::getWeaponType()
{
    return weaponType;
}
ArmorType Unit::getArmorType()
{
    return armorType;
}
TerrainBonuses Unit::getTerrainBonuses()
{
    return terrainBonuses;
}
Status Unit::getStatus()
{
    return status;
}

int Unit::setMovement(int movement)
{
    return this.movement = movement;
}
int Unit::setHp(int hp)
{
    return this.hp = hp;
}
int Unit::setMp(int mp)
{
    return this.mp = mp;
}
int Unit::setActions(int actions)
{
    return this.actions = actions;
}

Status Unit::setStatus(Status status)
{
    return this.status = status;
}