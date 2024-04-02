#include <iostream>
#include <fstream>
#include "Maps.hpp"
#include "json/json.h"

Maps::Maps() {
    loadMapData("maps.json");
}

void Maps::loadMapData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file: " << filename << std::endl;
        return;
    }

    Json::CharReaderBuilder builder;
    Json::Value root;
    std::string errs;
    if (!Json::parseFromStream(builder, file, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        return;
    }

    // Extract maps data from JSON
    const Json::Value& maps = root["maps"];
    for (const auto& mapData : maps) {
        Maps map;
        map.name = mapData["name"].asString();
        map.background = mapData["background"].asString();

        // Try to load background texture
        if (!map.backgroundTexture.loadFromFile("../Assets/InGame/" + map.background)) {
            std::cerr << "Failed to load background texture for map: " << map.name << std::endl;
            continue;
        }
        map.backgroundSprite.setTexture(map.backgroundTexture);

        // Temporary vector to hold characters for this map
        std::vector<Character> characters;

        // Load characters for the map
        const Json::Value& charactersData = mapData["characters"];
        for (const auto& characterData : charactersData) {
            std::string characterName = characterData["name"].asString();
            float x = characterData["x"].asFloat();
            float y = characterData["y"].asFloat();
            // Create and initialize characters based on names
            if (characterName == "Mario") {
                Mario mario;
                mario.setPosition(x, y);
                characters.push_back(mario);
            } else if (characterName == "HammerBros") {
                HammerBros hammerBros;
                hammerBros.setPosition(x, y);
                characters.push_back(hammerBros);
            }
        }

        // Assign the characters to the map
        map.characters = characters;

        // Now you can do whatever you want with the characters
        // For example, you could draw them or update them here

        // Note: If you want to keep track of multiple maps, you should use a vector of Maps
        // and add each map to that vector instead of overwriting the current map as you're doing here

    }

    file.close();
}

void Maps::update() {
    // Update map elements (e.g., characters, NPCs, etc.)
}

void Maps::draw(sf::RenderWindow& window) {
    // Draw map elements (e.g., background, characters, NPCs, etc.)
    for (const auto& map : mapData) {
        window.draw(map.backgroundSprite);
        for (const auto& character : map.characters) {
            character.draw(window);
        }
        // Draw other map elements
    }
}
