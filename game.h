#ifndef GAME_H
#define GAME_H
#include <Headers.h>


class Game : public sf::Sprite{
public:
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;
    sf::Vector2f velocity;

    void in_bounds(float x);
};

#endif // GAME_H
