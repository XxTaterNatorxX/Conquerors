// Initialize static member
#include "world.h"
world* world::instance = nullptr;

world::world(){
    day = 0;
    int location_amt = 25;
    int town_amt =     15;
    int player_amt =   25;
    int monster_amt =  20;
    int width =         7;
    int height =        7;
    
    map = new worldTile*[width];
    for(int x = 0; x < width; x++){
        map[x] = new worldTile[height];
        
        for(int y = 0; y < height; y++){
            map[x][y] = worldTile(x, y, faction::NEUTRAL);
        }
    }
    
    // TODO: create entities and locations
    for(int i = 0; i < location_amt; i++){

    }
    for(int i = 0; i < town_amt; i++){

    }
    //get players - from saves (subtract from player_amt)
    //create other random players to fill req
    for(int i = 0; i < player_amt; i++){
        
    }
    for(int i = 0; i < monster_amt; i++){
        
    }
}

// Don't forget to add cleanup in the destructor
world::~world() {
    // Clean up the 2D array
    int width = 7;
    for(int x = 0; x < width; x++) {
        delete[] map[x];
    }
    delete[] map;
}
