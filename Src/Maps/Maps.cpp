// Maps.cpp
#include "./Maps.hpp"
#include <iostream> // For error handling
#include <fstream>  // For file input
#include <jsoncpp/json/json.h> // JSON library

Maps::Maps() {
    // Load map data from JSON file
    loadMapData("maps.json");
}

void Maps::loadMapData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file: " << filename << std::endl;
        return;
    }

    Json::Value root;
    file >> root;

    // Extract maps data from JSON
    const Json::Value& maps = root["maps"];
    for (const auto& mapData : maps) {
        Map map;
        map.name = mapData["name"].asString();
        map.backgroundFile = mapData["background"].asString();

        // Load background texture for the map
        if (!map.backgroundTexture.loadFromFile(map.backgroundFile)) {
            std::cerr << "Failed to load background texture for map: " << map.name << std::endl;
            continue;
        }
        map.backgroundSprite.setTexture(map.backgroundTexture);

        // Load characters for the map
        const Json::Value& characters = mapData["characters"];
        for (const auto& characterData : characters) {
            std::string characterName = characterData["name"].asString();
            float x = characterData["x"].asFloat();
            float y = characterData["y"].asFloat();
            // Create and initialize characters based on their names
            if (characterName == "Mario") {
                Mario mario;
                mario.setPosition(x, y);
                map.characters.push_back(mario);
            } else if (characterName == "HammerBros") {
                HammerBros hammerBros;
                hammerBros.setPosition(x, y);
                map.characters.push_back(hammerBros);
            } // Add more character types as needed
        }

        mapsData.push_back(map);
    }

    file.close();
}

void Maps::update() {
    // Update map elements (e.g., characters, NPCs, etc.)
}

void Maps::draw(sf::RenderWindow& window) {
    // Draw map elements (e.g., background, characters, NPCs, etc.)
    for (const auto& map : mapsData) {
        window.draw(map.backgroundSprite);
        for (const auto& character : map.characters) {
            character.draw(window);
        }
        // Draw other map elements
    }
}
