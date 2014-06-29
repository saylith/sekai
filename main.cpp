#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map/battlemap.h"

void handleKeyboardEvent(BattleMap *map);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Text text;
    text.setString("test");
    text.setCharacterSize(24);

    BattleMap map(10,3);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Text textMap;
        sf::Text Menu;
        sf::Font font;
        font.loadFromFile("UbuntuMono-R.ttf");
        textMap.setFont(font);
        textMap.setString(map.printMap());
        textMap.setCharacterSize(24);
        textMap.setColor(sf::Color::White);

        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    handleKeyboardEvent(&map);
                    break;
                default:
                    break;
            }
        }
        window.clear();
        window.draw(textMap);
        window.display();
    }

    return 0;
}

void handleKeyboardEvent(BattleMap *map) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        map->moveFocus(0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        map->moveFocus(1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        map->moveFocus(2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
       map->moveFocus(3);
    }
}
