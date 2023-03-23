//
//  IdleState.hpp
//  Galaga
//
//  Created by Jake Houts on 3/22/23.
//

#ifndef IdleState_hpp
#define IdleState_hpp

#include "Enemy.hpp"

class IdleState : public EnemyState {
public:
    //constructor
    IdleState();
    
    //destructor
    ~IdleState();
    
    //update wasp postion
    void update(Enemy &enemy);
    
    //enter the IdleState
    void enter(Enemy &enemy);
    
    //exit the IdleState
    void exit(Enemy &enemy);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
    
    //helps render the idle animation
    bool swap;
};

#endif /* IdleState_hpp */
