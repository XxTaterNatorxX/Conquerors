#pragma once
#include "common.h"
#include "loot.h"
#include "guild.h"
#include <string>
using namespace std;
enum class locationType{
    DUNGEON,
    TOWN,
    RUINS,
    WILDERNESS
};
class location
{
protected:
    string name;
    locationType type;
    list<entity> entities;
    faction controllingFaction;

public:
    location(){
        this->name = string("unnamed");
        this->type = locationType::WILDERNESS;
        this->controllingFaction = faction::NEUTRAL;
    }
    location(string name, locationType t, faction f){
        this->name = name;
        this->type = t;
        this->controllingFaction = f;
    }
    void setControllingFaction(faction f){
        controllingFaction = f;
    }
    faction getControllingFaction(){
        return controllingFaction;
    }
    locationType getType(){
        return type;
    }
    string getName(){
        return name;
    }
};

class town : public location
{
private:
    list<loot> allLoot;
    guild* guildLocation;
    int money;
    int powerLevel;
public:
    town() : location() {
        this->type = locationType::TOWN;
        guildLocation = nullptr;
        powerLevel = 0;
        money = 0;
    }
    
    town(string name, faction f) : location(name, locationType::TOWN, f){
        *guildLocation = guild();
        powerLevel = 0;
        money = 500;
    }

    void setPowerLevel(int p){
        powerLevel = p;
    }
    int getPowerLevel(){
        return powerLevel;
    }
    void setMoney(int m){
        money = m;
    }
    int getMoney(){
        return money;
    }
    guild& getGuild(){
        return *guildLocation;
    }
    list<loot>& getAllLoot(){
        return allLoot;
    }
};

class dungeon : public location
{
private:
    list<loot> allLoot;
    int rewardMoney;
    int powerLevel;
    bool clear;
public:
    dungeon() : location() {
        this->type = locationType::DUNGEON;
        rewardMoney = 0;
        powerLevel = 0;
        clear = false;
    }
    
    dungeon(string name, faction f) : location(name, locationType::DUNGEON, f) {
        rewardMoney = 0;
        powerLevel = 0;
        clear = false;
    }

    void setReward(int r){
        rewardMoney = r;
    }
    void setPowerLevel(int p){
        powerLevel = p;
    }
    int getPowerLevel(){
        return powerLevel;
    }
    bool isCleared(){
        return clear;
    }
    int getReward(){
        return rewardMoney;
    }
    list<loot>& getAllLoot(){
        return allLoot;
    }
};

class ruins : public location
{
private:
    list<loot> allLoot;
public:
    ruins() : location() {
        this->type = locationType::RUINS;
    }
    
    ruins(string name, faction f) : location(name, locationType::RUINS, f) {
    }
    list<loot>& getAllLoot(){
        return allLoot;
    }
};

class wilderness : public location
{
public:
    wilderness() : location() {
        this->type = locationType::WILDERNESS;
    }
    
    wilderness(string name, faction f) : location(name, locationType::WILDERNESS, f) {
    }
};

