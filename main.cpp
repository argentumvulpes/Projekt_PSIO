#include <Headers.h>
#include "platform.h"
#include "player.h"
#include "point.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 800), "Powerpuff game");

    sf::View view = window.getView();

    sf::Texture powerpuff_girl1;
    if (!powerpuff_girl1.loadFromFile("textures/atomowka1.png")) { return 1; }

    sf::Texture background;
    if (!background.loadFromFile("textures/background1.png")) { return 1; }

    sf::Texture gameover;
    if (!gameover.loadFromFile("textures/gameover.png")) { return 1; }

    sf::Texture heart;
    if (!heart.loadFromFile("textures/point.png")) { return 1; }

    sf::Texture platform;
    if (!platform.loadFromFile("textures/platform.png")) { return 1; }

    sf::Font font;
    sf::Text score;
    sf::Text score2;
    if( !font.loadFromFile( "textures/FreeSansBold.ttf" ) ){return 1;}
    score.setFont( font );
    score.setCharacterSize( 30 );
    score.setFillColor(sf::Color(245,40,135));
    score2.setFont( font );
    score2.setCharacterSize( 30 );
    score2.setFillColor(sf::Color(245,40,135));

    Player player(sf::Vector2f(275.0, 600), powerpuff_girl1);

    std::vector<Game> pl;
    for(int i=0; i<12; i++){
    Platform platf(sf::Vector2f(rand()%550,i*(-100)+1000), platform);
    pl.emplace_back(platf);}

    std::vector<Game> po;
    Point pkt(sf::Vector2f(rand()%520,300), heart);
    po.emplace_back(pkt);

    pkt = Point(sf::Vector2f(rand()%520,700), heart);
    po.emplace_back(pkt);

    int points = 0;
    bool go =false;
    std::cout<<"Do yuo want to Quit?? press Q";

    sf::Clock clock;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                go = true;
            }

            for(auto &p : po){
                if(player.getGlobalBounds().intersects(p.getGlobalBounds())){
                    points++;
                    p.setPosition(rand()%550, player.getPosition().y-1000);
                }
                else if(p.getPosition().y-500 > player.getPosition().y){
                    p.setPosition(rand()%550, p.getPosition().y-1000);
                }
            }

            for(auto &p :pl){
                if(p.getPosition().y-500 > player.getPosition().y){
                    p.setPosition(rand()%550, p.getPosition().y-1000);
                }
            }

            for(auto &p : pl){
                player.collision(p);
            }

                player.in_bounds(player.getPosition().x);
            }

            float high_score = (-1*player.getPosition().y+600)/10;

            std::ostringstream out;
            out << static_cast< int >(high_score);
            score.setString(out.str());
            score.setPosition(10,player.getPosition().y - 400);

            std::ostringstream out2;
            out2 << static_cast< int >(points);
            score2.setString(out2.str());
            score2.setPosition(550,player.getPosition().y - 400);

            sf::Sprite sprite_go;
            sprite_go.setTexture(gameover);
            sprite_go.setPosition(0,player.getPosition().y - 400);

            sf::Sprite sprite_b;
            sprite_b.setTexture(background);
            sprite_b.setPosition(0,player.getPosition().y - 400);


        if(points == 100){go = true;}
        else if(high_score < -100){go = true;}
        else if(high_score > 10000){go = true;}

        if(go == false){

            player.move_x();
            player.gravity(clock);
            //player.move_y(clock);

            window.clear(sf::Color::Black);

            window.draw(sprite_b);
            window.draw(score);
            window.draw(score2);
            view.setCenter(300, player.getPosition().y);
            window.setView(view);

            for(const auto &p : pl){
                window.draw(p);}
            for(const auto &p : po){
                window.draw(p);}

            window.draw(player);}
        else{
            window.draw(sprite_go);
            window.draw(score);
            window.draw(score2);}

        window.display();
    }
    return 0;
}
