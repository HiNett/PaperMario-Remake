#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paper Mario - Remake");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../Assets/GameAssets/background-menu.jpeg");
    sf::Sprite spriteBackground(backgroundTexture);
    sf::Vector2u TextureSize;  //Added to store texture size.
    sf::Vector2u WindowSize;   //Added to store window size.

    TextureSize = backgroundTexture.getSize(); //Get size of texture.
    WindowSize = window.getSize();             //Get size of window.
    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    spriteBackground.setTexture(backgroundTexture);
    spriteBackground.setScale(ScaleX, ScaleY);      //Set scale.

    sf::Texture playMenu;
    playMenu.loadFromFile("../Assets/GameAssets/play-menu-selected.png");
    sf::Texture settingMenu;
    settingMenu.loadFromFile("../Assets/GameAssets/settings-menu-notSelected.png");
    sf::Texture exitMenu;
    exitMenu.loadFromFile("../Assets/GameAssets/exit-menu-notSelected.png");

    sf::RectangleShape startRectangle;
    startRectangle.setSize(sf::Vector2f(200, 100));
    startRectangle.setPosition(WindowSize.x/2.3, WindowSize.y/4.5);
    startRectangle.setTexture(&playMenu);

    sf::RectangleShape settingRectangle;
    settingRectangle.setSize(sf::Vector2f(300,100));
    settingRectangle.setPosition(WindowSize.x/2.5, WindowSize.y/2.5);
    settingRectangle.setTexture(&settingMenu);

    sf::RectangleShape exitRectangle;
    exitRectangle.setSize(sf::Vector2f(200,100));
    exitRectangle.setPosition(WindowSize.x/2.3, WindowSize.y/1.7);
    exitRectangle.setTexture(&exitMenu);

    window.clear();
    window.draw(spriteBackground);
    window.draw(startRectangle);
    window.draw(settingRectangle);
    window.draw(exitRectangle);
    window.display();
    }

    return 0;
}