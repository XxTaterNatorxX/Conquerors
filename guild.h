#pragma once
#include "common.h"
#include "loot.h"
#include "entity.h"
class guildRequest{
    private:
        int reward;
        bool elimination; // style of quest -elim or gather
        entity* entityTarget;
        loot* lootTarget;
    public:
        guildRequest(){
            reward = 0;
            elimination = true;
            entityTarget = nullptr;
            lootTarget = nullptr;
        }
        guildRequest(int r, entity* eTarget, loot* lTarget){
            reward = r;
            entityTarget = eTarget;
            lootTarget = lTarget;
            if(eTarget == nullptr){
                elimination = false;
            }
            else{
                elimination = true;
            }
        }
        int getReward(){
            return reward;
        }
        entity* getEntityTarget(){
            return entityTarget;
        }
        loot* getLootTarget(){
            return lootTarget;
        }
        bool isEliminationJob(){
            return elimination;
        }

};
class guild{
    private:
        list<guildRequest> requests;
        list<entity> adventuerers;
    public:
        guild(){}
        list<entity> getAdventuerers(){
            return adventuerers;
        }
        list<guildRequest> getRequests(){
            return requests;
        }
};