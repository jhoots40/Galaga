//
//  DeathState.hpp
//  Galaga
//
//  Created by Jake Houts on 3/22/23.
//

#ifndef DeathState_hpp
#define DeathState_hpp

#include "Enemy.hpp"

class DeathState : public EnemyState {
public:
    //constructor
    DeathState();
    
    //destructor
    ~DeathState();
    
    //enter the DeathState
    void enter(Enemy &enemy);
    
    //exit the DeathState
    void exit(Enemy &enemy);
    
    //update wasp postion
    void update(Enemy &b);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
};

#endif /* DeathState_hpp */
