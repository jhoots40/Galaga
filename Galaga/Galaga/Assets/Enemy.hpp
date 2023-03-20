//
//  Enemy.hpp
//  Galaga
//
//  Created by Jake Houts on 3/19/23.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "LTexture.hpp"

class Enemy {
public:
    //Main loop functions
    virtual void handleEvent( SDL_Event &e ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool checkCollision(SDL_Rect collider) = 0;
    virtual SDL_Rect getCollider() = 0;

    //Make sure to call child destructors
    virtual ~Enemy(){};
};


#endif /* Enemy_hpp */
