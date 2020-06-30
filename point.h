#ifndef POINT_H
#define POINT_H
#include <Headers.h>

class Point : public Game{
public:
    Point(const sf::Vector2f &position, const sf::Texture &texture);
};


#endif // POINT_H
