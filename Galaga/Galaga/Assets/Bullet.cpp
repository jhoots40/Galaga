//
//  Bullet.cpp
//  Galaga
//
//  Created by Jake Houts on 3/18/23.
//

#include "Bullet.hpp"
#include "Globals.h"

//constructor
Bullet::Bullet(float x, float y) {
    xPos = x;
    yPos = y;
    
    //speed will always be 100
    speed = 400;
    
    //set collision box and bulletTexture
    bulletTexture = &playerBullet;
    bulletCollider.x = xPos;
    bulletCollider.y = yPos;
    bulletCollider.w = bulletTexture->getWidth();
    bulletCollider.h = bulletTexture->getHeight();
    
    //bullet starts on screen
    onScreen = true;
}

//destructor
Bullet::~Bullet() {
    //nullify pointer
    bulletTexture = NULL;
}

//update bullet position
void Bullet::update(){
    yPos -= BULLET_VEL * dt;
    bulletCollider.y = yPos;
    if(yPos < -16) onScreen = false;
}

//render bullet;
void Bullet::render(){
    bulletTexture->render(xPos, yPos);
}
