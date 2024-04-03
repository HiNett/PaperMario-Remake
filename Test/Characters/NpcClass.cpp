#include <fstream>
#include <iostream> // Include for std::cerr
#include "../json/json.h" // Include JSON library
#include "./Character.hpp"

NPC::NPC(const std::string& name, const std::string& jsonFilename) {
    // Load NPC data from JSON
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

    const Json::Value& npcs = root["npcs"];
    for (const auto& npcData : npcs) {
        std::string npcName = npcData["name"].asString();
        if (npcName == name) {
            lifePoint = npcData["lifePoint"].asInt();
            power = npcData["power"].asInt();
            defense = npcData["defense"].asInt();
            aggressive = npcData["aggressive"].asBool();
            attributionExperiencePoint = npcData["attributionExperiencePoint"].asInt();
            jumpDenied = npcData["jumpDenied"].asBool();
            hammerDenied = npcData["hammerDenied"].asBool();

            // Load NPC texture
            std::string texturePath = npcData["texturePath"].asString();
            if (!texture.loadFromFile(texturePath)) {
                std::cerr << "Failed to load texture: " << texturePath << std::endl;
                return;
            }

            // Set the texture rectangle
            sf::IntRect intRect;
            intRect.left = npcData["intRect"]["left"].asInt();
            intRect.top = npcData["intRect"]["top"].asInt();
            intRect.width = npcData["intRect"]["width"].asInt();
            intRect.height = npcData["intRect"]["height"].asInt();
            sprite.setTexture(texture);
            sprite.setTextureRect(intRect);

            break;
        }
    }

    file.close();
}

void NPC::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void NPC::update() {
    // Update NPC logic here
}

void NPC::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}