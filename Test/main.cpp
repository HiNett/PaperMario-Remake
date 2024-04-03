// clear; g++ main.cpp ./Characters/NpcClass.cpp ./Characters/MarioClass.cpp -o "./Bin/Paper Mario - Remake.exe" -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
#include <SFML/Graphics.hpp>
#include <iostream>

#include "./Characters/Character.hpp" // Include the NPC class header
#include "./Maps/Maps.hpp" // Include the Maps class header

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "NPC Example");

    // Create the MAP
    Maps map("tutorial", "./Maps/maps.json", window);
    // Create an NPC
    Mario mario("Mario", "./Characters/mobs.json"); // Provide the name and JSON filename

    // Set the NPC's position
    mario.setPosition(200.0f, 100.0f);

    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            mario.handleInput(event);
        }

        // Update
        mario.update();
        // Clear the window
        window.clear();

        // Draw
        map.draw(window);
        mario.draw(window);

        // Display the window
        window.display();
    }

    return 0;
}
