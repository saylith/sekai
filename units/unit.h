#ifndef UNIT_H
#define UNIT_H

class Unit
{
    /**
    *   Member variables
    */
    int movement;
    int attack;
    int hp, maxHp;
    int mp, maxMp;
    int actions;

    WeaponType weaponType;
    ArmorType armorType;
    TerrainBonuses terrainBonuses;
    Status status;

    char representation;

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

        WeaponType getWeaponType();
        ArmorType getArmorType();
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