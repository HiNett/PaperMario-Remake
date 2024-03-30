#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "./loadingGame.cpp"
#include "./Class/MarioClass.cpp"
#include "./Class/HammerBrosClass.cpp"
using namespace std;

bool gameStarted = false;
bool gameLoaded = false;

int main()
{
    #ifndef WINDOW_H
    #define WINDOW_H
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paper Mario - Remake");
    #endif
    Mario mario;
    mario.setPosition(mario.xPosition, mario.yPosition);
    HammerBros hammerBrosTutorial;
    hammerBrosTutorial.setPosition(200, 800);
    window.setFramerateLimit(128);
    int choice=0, choiceLeft=1;
    bool isAKeyPressed=false, isChoiceWaiting=true;

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

    sf::Texture playMenuSelected;
    playMenuSelected.loadFromFile("../Assets/GameAssets/play-menu-selected.png");
    sf::Texture playMenuNotSelected;
    playMenuNotSelected.loadFromFile("../Assets/GameAssets/play-menu-notSelected.png");
    sf::Texture settingMenuSelected;
    settingMenuSelected.loadFromFile("../Assets/GameAssets/settings-menu-selected.png");
    sf::Texture settingMenuNotSelected;
    settingMenuNotSelected.loadFromFile("../Assets/GameAssets/settings-menu-notSelected.png");
    sf::Texture exitMenuSelected;
    exitMenuSelected.loadFromFile("../Assets/GameAssets/exit-menu-selected.png");
    sf::Texture exitMenuNotSelected;
    exitMenuNotSelected.loadFromFile("../Assets/GameAssets/exit-menu-notSelected.png");

    sf::RectangleShape startRectangleSelected;
    startRectangleSelected.setSize(sf::Vector2f(200, 100));
    startRectangleSelected.setPosition(WindowSize.x/2.3, WindowSize.y/4.5);
    startRectangleSelected.setTexture(&playMenuSelected);

    sf::RectangleShape startRectangleNotSelected;
    startRectangleNotSelected.setSize(sf::Vector2f(200, 100));
    startRectangleNotSelected.setPosition(WindowSize.x/2.3, WindowSize.y/4.5);
    startRectangleNotSelected.setTexture(&playMenuNotSelected);

    sf::RectangleShape settingRectangleSelected;
    settingRectangleSelected.setSize(sf::Vector2f(300,100));
    settingRectangleSelected.setPosition(WindowSize.x/2.5, WindowSize.y/2.5);
    settingRectangleSelected.setTexture(&settingMenuSelected);

    sf::RectangleShape settingRectangleNotSelected;
    settingRectangleNotSelected.setSize(sf::Vector2f(300,100));
    settingRectangleNotSelected.setPosition(WindowSize.x/2.5, WindowSize.y/2.5);
    settingRectangleNotSelected.setTexture(&settingMenuNotSelected);

    sf::RectangleShape exitRectangleSelected;
    exitRectangleSelected.setSize(sf::Vector2f(200,100));
    exitRectangleSelected.setPosition(WindowSize.x/2.3, WindowSize.y/1.7);
    exitRectangleSelected.setTexture(&exitMenuSelected);

    sf::RectangleShape exitRectangleNotSelected;
    exitRectangleNotSelected.setSize(sf::Vector2f(200,100));
    exitRectangleNotSelected.setPosition(WindowSize.x/2.3, WindowSize.y/1.7);
    exitRectangleNotSelected.setTexture(&exitMenuNotSelected);

    window.clear();
    window.draw(spriteBackground);
    window.draw(startRectangleSelected);
    window.draw(settingRectangleNotSelected);
    window.draw(exitRectangleNotSelected);
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            mario.handleInput(event);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && gameStarted == false) {
            if(choice >= 0 && choice <= 3){
                choice++;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleSelected);
                window.draw(settingRectangleNotSelected);
                window.draw(exitRectangleNotSelected);
                window.display();
            } else if(choice >= 4 && choice <= 7){
                choice++;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleNotSelected);
                window.draw(settingRectangleSelected);
                window.draw(exitRectangleNotSelected);
                window.display();
            } else if(choice >= 8 && choice <= 11){
                choice++;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleNotSelected);
                window.draw(settingRectangleNotSelected);
                window.draw(exitRectangleSelected);
                window.display();
            } else choice=0;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && gameStarted == false) {
            if(choice >= 0 && choice <= 3){
                choice--;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleSelected);
                window.draw(settingRectangleNotSelected);
                window.draw(exitRectangleNotSelected);
                window.display();
            } else if(choice >= 4 && choice <= 7){
                choice--;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleNotSelected);
                window.draw(settingRectangleSelected);
                window.draw(exitRectangleNotSelected);
                window.display();
            } else if(choice >= 8 && choice <= 11){
                choice--;
                window.clear();
                window.draw(spriteBackground);
                window.draw(startRectangleNotSelected);
                window.draw(settingRectangleNotSelected);
                window.draw(exitRectangleSelected);
                window.display();
            } else choice = 10;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            if(choice >= -1 && choice <= 3){
                gameStarted = true;
            } else if(choice >= 4 && choice <= 7){
                //loadSettings();
            } else if(choice >= 8 && choice <= 12){
                window.close();
            }
        }

        if(gameStarted == true){
            if(gameLoaded == false){
                loadingGame();
                gameLoaded = true;
            }
            if(gameLoaded == true){
                if(marioPhase == 0){
                    // Tutorial
                    sf::Texture tutorialTexture;
                    tutorialTexture.loadFromFile("../Assets/InGame/tutorial/background.png");

                    sf::Sprite tutorialSprite(tutorialTexture);
                    sf::Vector2u TextureSize;  //Added to store texture size.
                    sf::Vector2u WindowSize;   //Added to store window size.

                    TextureSize = tutorialTexture.getSize(); //Get size of texture.
                    WindowSize = window.getSize();             //Get size of window.

                    float ScaleX = (float) WindowSize.x / TextureSize.x;
                    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

                    tutorialSprite.setTexture(tutorialTexture);
                    tutorialSprite.setScale(ScaleX, ScaleY);      //Set scale.
                    
                    // Create a rectangle, that is at the bottom of the map, take all the ground, and is 10% tall of the window
                    sf::RectangleShape ground(sf::Vector2f(WindowSize.x, WindowSize.y * 0.242));
                    ground.setPosition(0, WindowSize.y - WindowSize.y * 0.242);
                    ground.setFillColor(sf::Color::Green);

                    // mario.yPosition = WindowSize.y - WindowSize.y * 0.242 - 165;
                    mario.update();
                    window.clear();
                    window.draw(tutorialSprite);
                    window.draw(ground);
                    hammerBrosTutorial.draw(window);
                    mario.draw(window);
                    window.display();
                } else if(marioPhase == 1 && accessPhase >= 1){
                    // Phase 1
                } else if(marioPhase == 2 && accessPhase >= 2){
                    // Phase 2
                } else if(marioPhase == 3 && accessPhase >= 3){
                    // Phase 3
                } else if(marioPhase == 4 && accessPhase >= 4){
                    // Phase 4
                } else if(marioPhase == 5 && accessPhase >= 5){
                    // Phase 5
                } else if(marioPhase == 6 && accessPhase >= 6){
                    // Phase 6
                } else if(marioPhase == 7 && accessPhase >= 7){
                    // Phase 7
                } else if(marioPhase == 8 && accessPhase >= 8){
                    // Phase 8
                } else if(marioPhase == 9 && accessPhase >= 9){
                    // Phase 9
                } else if(marioPhase == 10 && accessPhase >= 10){
                    // Phase 10
                }
            }
        }
    }
    return 0;
}