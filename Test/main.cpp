// clear; g++ main.cpp ./Characters/NpcClass.cpp ./Characters/MarioClass.cpp -o "./Bin/Paper Mario - Remake.exe" -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
#include <SFML/Graphics.hpp>
#include <iostream>

#include "./Characters/Character.hpp" // Include the NPC class header
#include "./Maps/Maps.hpp" // Include the Maps class header

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "NPC Example");

    // Create the MAP with all the content
    Maps map("tutorial", "./Maps/maps.json", window);


    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            map.handleInput(event);
        }

        // Update
        map.update();
        
        // Clear the window
        window.clear();

        // Draw
        map.draw(window);

        // Display the window
        window.display();
    }

    return 0;
}
