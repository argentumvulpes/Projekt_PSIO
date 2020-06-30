#ifndef PLATFORM_H
#define PLATFORM_H
#include <Headers.h>


class Platform :public Game{
public:
    Platform(const sf::Vector2f &position, const sf::Texture &texture);
};

#endif // PLATFORM_H
