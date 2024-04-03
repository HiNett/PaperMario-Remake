#include <fstream>
#include <iostream> // Include for std::cerr
#include "../json/json.h" // Include JSON library
#include "./Maps.hpp"

Maps::Maps(const std::string& name, const std::string& jsonFilename, const sf::RenderWindow& window) {

    std::ifstream file(jsonFilename);
    if (!file.is_open()) { 
        std::cerr << "Failed to open JSON file: " << jsonFilename << std::endl;
        return;
    }

    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errs;
    if (!Json::parseFromStream(builder, file, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        return;
    }

    const Json::Value& maps = root["maps"];
    for (const auto& mapData : maps) {
        std::string mapName = mapData["name"].asString();
        if (mapName == name) {

            std::string texturePath = mapData["texturePath"].asString();
            if (!texture.loadFromFile(texturePath)) {
                std::cerr << "Failed to load texture: " << texturePath << std::endl;
                return;
            }

            textureSize = texture.getSize();
            windowSize = window.getSize();

            float scaleX = (float) (windowSize.x) / textureSize.x;
            float scaleY = (float) (windowSize.y) / textureSize.y;
            sprite.setTexture(texture);
            sprite.setScale(scaleX, scaleY);
            sprite.setPosition(0, 0);

            const Json::Value& characters = mapData["characters"];
            for (const auto& characterData : characters) {
                std::string characterName = characterData["name"].asString();
                float xPosition = characterData["xPosition"].asFloat();
                // Create NPC object
                NPC* npc = new NPC(characterName, "./Characters/mobs.json"); // Adjust JSON filename as needed
                npc->setPosition(xPosition, mapData["ground_height"].asFloat()); // Set position
                // Add NPC to a collection or use as needed
                std::cout << characterName << " have been printed" << std::endl;
                npcs.push_back(npc);
            }

        }
    }
}

void Maps::update() {
    // Update Maps logic here
}

void Maps::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    for (auto& npc : npcs) {
        npc->draw(window);
    }
}