#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "map/battlemap.h"
#include "battle/battle.h"

void handleKeyboardEvent();

Battle battle;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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

        sf::Image image;
        image.loadFromFile("map/terrain_sprites/generic.png");
        image.createMaskFromColor(sf::Color(0,255,0,255));

        sf::Texture texture;
        texture.loadFromImage(image, sf::IntRect(0,0,144,144));

        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setColor(sf::Color(0,255,0));

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
        window.clear();
        window.draw(textMap);
        window.draw(sprite);
        window.draw(textMenu);

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