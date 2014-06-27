class Unit
{
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
        int getAttackDamage(Unit enemy, Terrain terrain);

        int getMovement()
        {
            return movement;
        }
        int getAttack()
        {
            return attack;
        } 
        int getHp()
        {
            return hp;
        }
        int getMaxHp()
        {
            return maxHp;
        }
        int getMp()
        {
            return mp;
        }
        int getMaxMp()
        {
            return maxMp;
        }
        int getActions()
        {
            return actions;
        }

        WeaponType getWeaponType()
        {
            return weaponType;
        }
        ArmorType getArmorType()
        {
            return armorType;
        }
        TerrainBonuses getTerrainBonuses()
        {
            return terrainBonuses;
        }
        Status getStatus()
        {
            return status;
        }

        int setMovement(int movement)
        {
            return this.movement = movement;
        }
        int setHp(int hp);
        {
            return this.hp = hp;
        }
        int setMp(int mp)
        {
            return this.mp = mp;
        }
        int setActions(int actions)
        {
            return this.actions = actions;
        }

        Status setStatus(Status status)
        {
            return this.status = status;
        }

        char getRepresentation()
        {
            return representation;
        }
}
