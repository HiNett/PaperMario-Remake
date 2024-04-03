// clear; g++ main.cpp ./Characters/NpcClass.cpp ./Characters/MarioClass.cpp -o "./Bin/Paper Mario - Remake.exe" -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
#include <SFML/Graphics.hpp>
#include "./Characters/Character.hpp" // Include the NPC class header

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "NPC Example");

    // Create an NPC
    Mario mario("Mario", "./Characters/mobs.json"); // Provide the name and JSON filename
    NPC npc("Hammer Bro", "./Characters/mobs.json"); // Provide the name and JSON filename

    // Set the NPC's position
    npc.setPosition(100.0f, 100.0f);
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
        npc.update();
        mario.update();
        // Clear the window
        window.clear();

        // Draw
        npc.draw(window);
        mario.draw(window);

        // Display the window
        window.display();
    }

    return 0;
}
