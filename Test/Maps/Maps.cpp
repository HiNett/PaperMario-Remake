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
            
            ground.setSize(sf::Vector2f(8000, mapData["groundHeight"].asFloat()));
            float minGroundY = windowSize.y - mapData["groundHeight"].asFloat();
            std::cout << minGroundY << std::endl;
            ground.setPosition(0, minGroundY);
            ground.setFillColor(sf::Color::Green);

            // Create Mario object
            mario = new Mario("Mario", "./Characters/mobs.json", minGroundY); // Adjust JSON filename as needed
            mario->setPosition(20, minGroundY - 167); // Set position

            const Json::Value& characters = mapData["characters"];
            for (const auto& characterData : characters) {
                std::string characterName = characterData["name"].asString();
                float xPosition = characterData["xPosition"].asFloat();
                
                // Create NPC object
                NPC* npc = new NPC(characterName, "./Characters/mobs.json"); // Adjust JSON filename as needed
                float spriteHeight = npc->getHeight();
                npc->setPosition(xPosition, minGroundY - spriteHeight); // Set position

                // Add NPC to a collection or use as needed
                npcs.push_back(npc);
            }

        }
    }
}


void Maps::update() {
    if (mario != nullptr) {
        mario->update();
    }
}

void Maps::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    for (auto& npc : npcs) {
        npc->draw(window);
    }
    mario->draw(window);
}
// Take the Mario::handle
void Maps::handleInput(sf::Event& event) {
    if (mario != nullptr) {
        mario->handleInput(event);
    }
}