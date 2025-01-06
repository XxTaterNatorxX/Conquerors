#include "loot.h"
using namespace std;
void loot::addRandomBuff(){
    int x = Random::randInt(1, 8);
    //check if effect is there
    //add effect
    switch(x){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
    }
}
void loot::addRandomEffect(){

}
int loot::determineRank(int min, int max){
    int x = Random::randInt(min,max);
    int toDecode = 0;
    if(x <= 30){
        //E rank item
        setRank(lootRank::E);
        setValue(200);
        toDecode = 1;
        return toDecode;
    }
    else if(x <= 55){
        //D rank item
        setRank(lootRank::D);
        setValue(300);
        toDecode = 2;
        if(Random::randBool){
            toDecode += 100;
            setValue(getValue() + 50);
        }
        return toDecode;
    }
    else if(x <= 70){
        //c rank item
        setRank(lootRank::C);
        setValue(500);

        toDecode = 104;
        if(Random::randBool){
            toDecode += 100;
            setValue(getValue() + 50);
        }
        return toDecode;
    }
    else if(x <= 85){
        //B rank item
        setRank(lootRank::B);
        setValue(600);

        toDecode = 205;
        if(Random::randBool){
            toDecode += 100;
            setValue(getValue() + 60);
        }
        return toDecode;
    }
    else if(x <= 98){
        //A rank item
        setRank(lootRank::A);
        setValue(700);

        toDecode = 306;
        if(Random::randBool){
            toDecode += 100;
            setValue(getValue() + 70);
        }
        return toDecode;
    }
    else{
        //S rank item
        setRank(lootRank::S);
        setValue(1200);

        toDecode = 408;
        if(Random::randBool){
            toDecode += 100;
            setValue(getValue() + 100);
        }
        return toDecode;
    }
}
void loot::create(){
    lootType lt = lootType(Random::randInt(0,10));
    int stat = determineRank(1, 100);
    //base stat buffs
    for(int i = 0; i < (stat % 100); i++){
        addRandomBuff();
    }
    //effects
    for(int i = (stat % 100); i < stat; i += 100){
        addRandomEffect();
    }
    
}
void loot::create(lootRank rank){
    
}