#pragma once
#include "common.h"
#include "effect.h"
using namespace std;
enum class lootRank{
    S,
    A,
    B,
    C,
    D,
    E
};
class loot{
    private:
        int value;
        lootType type;
        lootRank rank;
        int resistance;
        int healthboost;
        int agility;
        int strength;
        list<effect*> effects;
        
    public:
        loot() {
            value = 0;
            resistance = 0;
            healthboost = 0;
            agility = 0;
            strength = 0;
        }
        void create();
        void create(lootRank rank);
        void addEffect(effect* newEffect) {
            effects.add(newEffect);
        }

        list<effect*>& getEffects() {
            return effects;
        }

        int getValue() const { return value; }
        lootType getType() const { return type; }
        lootRank getRank() const { return rank; }
        int getResistance() const { return resistance; }
        int getHealthBoost() const { return healthboost; }
        int getAgility() const { return agility; }
        int getStrength() const { return strength; }
        
        void setValue(int v) { value = v; }
        void setType(lootType t) { type = t; }
        void setRank(lootRank r) { rank = r; }
        void setResistance(int r) { resistance = r; }
        void setHealthBoost(int h) { healthboost = h; }
        void setAgility(int a) { agility = a; }
        void setStrength(int s) { strength = s; }

        int determineRank(int min, int max);
        void addRandomBuff();
        void addRandomEffect();
};