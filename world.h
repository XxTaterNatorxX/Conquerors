#pragma once
#include "common.h"
#include "entity.h"
#include "locations.h"
using namespace std;

class worldTile
{
private:
    int x, y;
    list<entity> entities;
    list<location> locations;
    faction controllingFaction;
public:
    worldTile() {
        x = -1;
        y = -1;
        controllingFaction = faction::NEUTRAL;
    }
    worldTile(int x, int y, faction faction) {
        this->x = x;
        this->y = y;
        this->controllingFaction = faction;
    }
    ~worldTile();
    void setControllingFaction(faction faction){
        controllingFaction = faction;
    }
    faction getControllingFaction(){
        return controllingFaction;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    list<entity>& getEntities(){
        return entities;
    }
    list<location>& getLocations(){
        return locations;
    }
};

class world
{
private:
    worldTile** map;
    int day;
    list<entity> allEntities;

    world();
    world(const world&) = delete;
    world& operator=(const world&) = delete;
    
    static world* instance;

public:
    ~world();
    
    static world* getInstance() {
        if (instance == nullptr) {
            instance = new world();
        }
        return instance;
    }
    worldTile** getMap(){
        return map;
    }
    int getDay(){
        return day;
    }
    void incrementDay(){
        day ++;
    }
    list<entity>& getAllEntities(){
        return allEntities;
    }
};

