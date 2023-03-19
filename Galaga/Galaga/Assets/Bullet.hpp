//
//  Bullet.hpp
//  Galaga
//
//  Created by Jake Houts on 3/18/23.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include "LTexture.hpp"

class Bullet {
public:
    //bullet speed
    static const int BULLET_VEL = 700;
    
    //constructor
    Bullet(float x, float y);
    
    //destructor
    ~Bullet();
    
    //update bullet position
    void update();
    
    //render bullet;
    void render();
    
    //check is bullet is on screen
    bool isOnScreen() { return onScreen; }
    
private:
    //bullet position
    float xPos, yPos;
    
    //bullet speed;
    float speed;
    
    //pointer to bullet texture
    LTexture *bulletTexture;
    
    //flag for if bullet is on screen
    bool onScreen;
    
    //Players collision box
    SDL_Rect bulletCollider;
};

#endif /* Bullet_hpp */
