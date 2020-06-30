#ifndef PLAYER_H
#define PLAYER_H
#include <Headers.h>

class Player : public Game{
public:
    Player(const sf::Vector2f &position, const sf::Texture &texture);

    float dt;
    void move_x();
    //void move_y(sf::Clock &clock);
    void gravity(sf::Clock &clock);
    sf::Vector2f velocity;
    void collision(sf::Sprite &s);
    int bounds_bottom_ = 800;
    float acceleration_x_ = 0;
    float acceleration_y_ = 0;
    void setAcceleration(float acceleration_x, float acceleration_y);
};

#endif // PLAYER_H
