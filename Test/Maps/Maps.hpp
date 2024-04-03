#ifndef MAPS_HPP
#define MAPS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../json/json.h" 
#include "../Characters/Character.hpp"


class Maps {
    private:
        sf::Texture texture;
        sf::Sprite sprite;

        sf::Vector2u textureSize;
        sf::Vector2u windowSize;

        std::vector<NPC*> npcs;

    public:
        // Arguments
        std::string name;
        std::string background;
        float ground_height;
        

        // Methods
        Maps(const std::string& name, const std::string& jsonFilename, const sf::RenderWindow& window);
        void update();
        void draw(sf::RenderWindow& window);

        ~Maps() {
            for (auto& npc : npcs) {
                delete npc;
            }
        }
};

#endif 
