#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map/battlemap.h"
#include "battle/battle.h"

void handleKeyboardEvent();

Battle battle;

int main()
{
    sf::RenderWindow window(sf::VideoMode(432, 144), "My window");

    sf::Text text;
    text.setString("test");
    text.setCharacterSize(24);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        
        sf::Text textMap;
        sf::Text textMenu;
        
        sf::Font font;
        font.loadFromFile("UbuntuMono-R.ttf");
        textMap.setFont(font);
        textMenu.setFont(font);

        textMap.setCharacterSize(24);
        textMenu.setCharacterSize(24);

        textMap.setColor(sf::Color::White);
        textMenu.setColor(sf::Color::White);

        textMap.setString(battle.getMap());
        textMenu.setString(battle.getMenu());

        textMenu.setPosition(350, 0);

        sf::Texture texture;
        if (!texture.loadFromFile("map/terrain_sprites/generic.png")) {
            return 0; //error
        }
        sf::ConvexShape one;
        one.setPointCount(6);
        one.setPoint(0, sf::Vector2f(0, 30));
        one.setPoint(1, sf::Vector2f(0, 30 + 21));
        one.setPoint(2, sf::Vector2f(48, 60 + 21));
        one.setPoint(3, sf::Vector2f(96, 30 + 21));
        one.setPoint(4, sf::Vector2f(96, 30));
        one.setPoint(5, sf::Vector2f(48, 0));
        one.setPosition(24, 42);

        sf::ConvexShape oneb;
        oneb.setPointCount(4);
        oneb.setPoint(0, sf::Vector2f(0, 30));
        oneb.setPoint(1, sf::Vector2f(48, 60));
        oneb.setPoint(2, sf::Vector2f(96, 30));
        oneb.setPoint(3, sf::Vector2f(48, 0));
        oneb.setFillColor(sf::Color(144,144,144,255));
        oneb.setPosition(24, 42);

        sf::ConvexShape onec;
        onec.setPointCount(4);
        onec.setPoint(0, sf::Vector2f(0, 30));
        onec.setPoint(1, sf::Vector2f(48, 60));
        onec.setPoint(2, sf::Vector2f(96, 30));
        onec.setPoint(3, sf::Vector2f(48, 0));
        onec.setFillColor(sf::Color(144,144,144,255));
        onec.setPosition(168, 21);

        sf::ConvexShape oned;
        oned.setPointCount(4);
        oned.setPoint(0, sf::Vector2f(0, 30));
        oned.setPoint(1, sf::Vector2f(48, 60));
        oned.setPoint(2, sf::Vector2f(96, 30));
        oned.setPoint(3, sf::Vector2f(48, 0));
        oned.setFillColor(sf::Color(144,144,144,255));
        oned.setPosition(312, 50);

        sf::ConvexShape two;
        two.setPointCount(6);
        two.setPoint(0, sf::Vector2f(0, 30));
        two.setPoint(1, sf::Vector2f(0, 30 + 42));
        two.setPoint(2, sf::Vector2f(48, 60 + 42));
        two.setPoint(3, sf::Vector2f(96, 30 + 42));
        two.setPoint(4, sf::Vector2f(96, 30));
        two.setPoint(5, sf::Vector2f(48, 0));
        two.setPosition(168, 21);

        sf::ConvexShape three;
        three.setPointCount(6);
        three.setPoint(0, sf::Vector2f(0, 30));
        three.setPoint(1, sf::Vector2f(0, 30 + 13));
        three.setPoint(2, sf::Vector2f(48, 60 + 13));
        three.setPoint(3, sf::Vector2f(96, 30 + 13));
        three.setPoint(4, sf::Vector2f(96, 30));
        three.setPoint(5, sf::Vector2f(48, 0));
        three.setPosition(312, 50);

        
        //one.setTexture(&texture);
        //one.setTextureRect(sf::IntRect(0, 0, 86, 56));

        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    handleKeyboardEvent();
                    break;
                default:
                    break;
            }
        }
        window.clear(sf::Color (0, 255, 0, 255));
       // window.draw(textMap);
        window.draw(textMenu);
        window.draw(one);
        window.draw(two);
        window.draw(three);
        window.draw(oneb);
        window.draw(onec);
        window.draw(oned);
        
        //window.draw(sprite);
        window.display();
    }

    return 0;
}

void handleKeyboardEvent() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        battle.keyboardRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        battle.keyboardUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        battle.keyboardLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        battle.keyboardDown();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        battle.keyboardZ();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        battle.keyboardX();
    }
}