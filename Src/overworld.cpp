#include <SFML/Graphics.hpp>
#include "./MarioSprite.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Paper Mario - Remake");
    MarioSprite marioSprite;
    marioSprite.setPosition(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            marioSprite.handleInput(event);
        }

        marioSprite.update();

        window.clear();
        marioSprite.draw(window);
        window.display();
    }

    return 0;
}
