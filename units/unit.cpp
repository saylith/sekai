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
        int calculateDamageTaken(Unit enemy, Terrain terrain);


        int getMovement();
        int getAttack();
        int getHp();
        int getMaxHp();
        int getMp();
        int getMaxMP();
        int getActions();

        WeaponType getWeaponType();
        ArmorType getArmorType();
        TerrainBonuses getTerrainBonuses();
        Status getStatus();

        int setMovement();
        int setAttack();
        int setHp();
        int setMaxHp();
        int setMp();
        int setMaxMP();
        int setActions();

        Status setStatus();
}
