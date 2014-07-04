#ifndef UNIT_H
#define UNIT_H

class Unit
{
    public:
        struct Stats {
            int MOR; // Morale: the Unit's HP
            int GEN; // General: Charge and Counter damage, skill defense
            int ATK; // Attack: Damage over time, Morale damage
            int TEC; // Technique: Charge and Counter reduction, skill effectiveness
            int LUK; // Luck: Chance for criticals
            int MOV; // Movement: number of spaces per turn
        };

        Stats getStats();
        Stats setStats(int mor, int gen, int atk, int tec, int luk, int mov);
        int getMOR();
        int getGEN();
        int getATK();
        int getTEC();
        int getLUK();
        int getMOV();

        int setMOR(int mor);
        int setGEN(int gen);
        int setATK(int atk);
        int setTEC(int tec);
        int setLUK(int luk);
        int setMOV(int mov);        

        enum Weapon {
            SWORD, AXE, LANCE, 
            BOW, CROSSBOW, GUN, 
            WAND, STAFF, TOME
        };

        enum Direction {
            NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3
        };

        Weapon getWeapon();
        Weapon setWeapon(Weapon weapon);
        bool isMelee();
        bool isRanged();
        bool isMagic();

        enum Armor {
            LIGHT, HEAVY, CLOTH
        };
        Armor getArmor();
        Armor setArmor(Armor armor);

        enum Type {
            FOOT, MOUNT, AIR
        };
        Type getType();
        Type setType(Type type);

        enum Gender {
            MALE,
            FEMALE,
            NA //Inorganic units would not be applicable for gender, added option for this
        };
        Gender getGender();
        Gender setGender(Gender gender);

        enum Status {
            SLEEP,
            POISON,
            SLOW,
            WEAK,
            SILENCE,
            STUN,
            NONE
        };
        Status getStatus();
        Status setStatus(Status status);

     //   int getAttackDamage(Unit enemy, Square::Terrain terrain);
        int getMovement();
        char getRepresentation();
        // sf::Sprite getSprite();

        bool isAce();
        bool setAce(bool ace);
        Direction getDirection();
        Direction setDirection(Direction direction);


    private:
        Stats stats;
        Weapon weapon;
        Armor armor;
        Type type;
        Gender gender;
        Status status;
        Direction direction;
        bool ace;
      //  sf::Sprite sprite;
        //std::map<Square::Terrain, float> terrainBonus;

    protected:
        char representation;
};

#endif
