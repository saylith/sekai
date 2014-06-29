#ifndef UNIT_H
#define UNIT_H

#include "armor.h"
#include "weapon.h"
#include "terrain.h"
#include "status.h"

class Unit
{
    /**
    *   Member variables
    */


    protected:
        char representation;
        int movement;
        int attack;
        int hp, maxHp;
        int mp, maxMp;
        int actions;

        Weapon weapon;
        Armor armor;
        TerrainBonuses terrainBonuses;
        Status status;

    public:
        /**
        *   getAttackDamage
        *       Determines damage done to enemy
        */
        int getAttackDamage(Unit enemy, Terrain terrain);

        /**
        *   Getters
        */
        int getMovement();
        int getAttack();
        int getHp();
        int getMaxHp();
        int getMp();
        int getMaxMp();
        int getActions();
        char getRepresentation();

        Weapon getWeapon();
        Armor getArmor();
        TerrainBonuses getTerrainBonuses();
        Status getStatus();

        /**
        *   Setters
        */
        int setMovement(int movement);
        int setHp(int hp);
        int setMp(int mp);
        int setActions(int actions);
        Status setStatus(Status status);

        
};

#endif