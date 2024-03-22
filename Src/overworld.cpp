#include <SFML/Graphics.hpp>
#include "./Class/Class.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 600), "Paper Mario - Remake");

    // Load the texture containing all the sprites
    sf::Texture texture;
    if (!texture.loadFromFile("../Assets/Sprites/MarioSprites.png")) {
        // Handle error
        return 1;
    }

    // Define rectangles for each sprite within the texture
    sf::IntRect marioBody(0, 0, 108, 180); // Example: Mario sprite with size 32x32
    // Define more rectangles for other sprites as needed

    // Create Mario instance with the loaded texture
    Mario mario(texture);

    // Create Mario sprite and set its texture
    sf::Sprite marioSprite(texture, marioBody);
    // Create more sprites for other characters or objects as needed

    // Position the Mario sprite
    float xPosition = 200;
    float yPosition = 100;
    marioSprite.setPosition(xPosition, yPosition);
    // Position more sprites as needed

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw the sprites
        window.draw(marioSprite);
        // Draw more sprites as needed

        window.display();
    }

    return 0;
}
