class Unit
{
    int movement;
    int attack;
    int hp;
    int mp;

    WeaponType weaponType;
    ArmorType armorType;
    TerrainBonuses terrainBonuses;

    char representation;

    public:
        int getAttackDamage(Unit enemy, Terrain terrain);

        int getMovement();
        int changeMovement(change);
        
        int changeHP(int change);
        int changeMP(int change);

}
