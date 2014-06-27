class Unit
{
    int movement;
    int attack;
    int hp, maxHp;
    int mp, maxMp;

    WeaponType weaponType;
    ArmorType armorType;
    TerrainBonuses terrainBonuses;
    Status status;

    char representation;

    public:
        int getAttackDamage(Unit enemy, Terrain terrain);

        int getMovement();
        int changeMovement(change);
        
        int changeHP(int change);
        int changeMP(int change);

}
