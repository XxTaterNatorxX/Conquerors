#pragma once
#include <string>
using namespace std;
enum class effectType {
    BUFF,       // Positive effect for the wearer
    DEBUFF,     // Negative effect for the attacker
    PASSIVE     // Constant effect
};
class effect {
protected:
    string name;
    string desc;
    effectType type;
    int magnitude;    // How strong the effect is
    int id;

public:
    effect(int id, string name, string desc, effectType type, int magnitude) {
        this->name = name;
        this->desc = desc;
        this->type = type;
        this->magnitude = magnitude;
        this->id = id;
    }
    virtual void apply() = 0;  // Pure virtual function
    
    string getName() { return name; }
    string getDesc() { return desc; }
    effectType getType() { return type; }
    int getMagnitude() { return magnitude; }
};
class DamageBoostEffect : public effect {
public:
    DamageBoostEffect(int magnitude) : effect(1, "Damage Boost", "Increases damage dealt", effectType::BUFF, magnitude){}
    
    void apply() override {
        // Implementation for boosting damage
    }
};
class DefenseEffect : public effect {
public:
    DefenseEffect(int magnitude) : effect(2, "Defensive", "Boosts Defense", effectType::BUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class PoisonEffect : public effect {
public:
    PoisonEffect(int magnitude) : effect(3, "Poisonous", "Poisons attackers", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class FireEffect : public effect {
public:
    FireEffect(int magnitude) : effect(4, "Fire Aspect", "Sets attackers on fire", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class ShockingEffect : public effect {
public:
    ShockingEffect(int magnitude) : effect(5, "Shocking", "Electrocutes attackers", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class WaterEffect : public effect {
public:
    WaterEffect(int magnitude) : effect(6, "Water Edge", "Deals water damage to attackers", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class FrostbiteEffect : public effect {
public:
    FrostbiteEffect(int magnitude) : effect(7, "Frostbite", "Applies frostbite to attackers", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};
class NatureEffect : public effect {
public:
    NatureEffect(int magnitude) : effect(8, "Natural", "deals nature damage to attackers", effectType::DEBUFF, magnitude) {}
    
    void apply() override {
        // Implementation for poison effect
    }
};