#include <SFML/Graphics.hpp>
#include "./MarioSprite.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Paper Mario - Remake");

    MarioSprite marioSprite; // Crée l'objet MarioSprite en utilisant le constructeur par défaut
    // Ne chargez pas la texture ici, utilisez la fonction loadTexture dans la boucle principale

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
