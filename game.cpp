#include "game.h"


void Game::in_bounds(float x){
    if(x < -67){
        this->setPosition(600, this->getPosition().y);
    }
    if(x > 667){
        this->setPosition(0, this->getPosition().y);
    }
}


