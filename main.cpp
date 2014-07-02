#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map/battlemap.h"
#include "battle/battle.h"
#include <iostream>

sf::View handleKeyboardEvent(sf::View mapView);

Battle battle;

int main()
{
    int windowWidth = 800;
    int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "sekai");
    window.setVerticalSyncEnabled(true);

    sf::Text text;
    text.setString("test");
    text.setCharacterSize(24);

    sf::View mapView(sf::FloatRect(-650, -200, 1000, 750));

        window.setView(mapView);
        mapView.setViewport(sf::FloatRect(0,0,1,1));

    //run the program as long as the window is open
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
        textMap.setPosition(-600, -150);
        textMenu.setString(battle.getMenu());
        textMenu.setPosition(-500, -150);

        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    window.setView(handleKeyboardEvent(window.getView()));
                    break;
                default:
                    break;
            }
            
        }
        

        window.clear();
        window.draw(textMap);
        window.draw(textMenu);

        std::vector<sf::Sprite> spriteMap = battle.drawMap();
        for(sf::Sprite sprite : spriteMap) {
            window.draw(sprite);
        }

        window.display();
    }

    return 0;
}

sf::View handleKeyboardEvent(sf::View mapView) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        battle.keyboardRight();
        //mapView.move(1,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        battle.keyboardUp();
        //mapView.move(0,-1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        battle.keyboardLeft();
        //mapView.move(-1,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        battle.keyboardDown();
//        mapView.move(0,1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        battle.keyboardZ();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        battle.keyboardX();
    }
    return mapView;
}