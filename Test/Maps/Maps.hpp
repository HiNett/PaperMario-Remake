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
        Mario* mario;

        sf::RectangleShape ground;

    public:
        // Arguments
        std::string name;
        std::string background;
        float ground_height;
        

        // Methods
        Maps(const std::string& name, const std::string& jsonFilename, const sf::RenderWindow& window);
        void update();
        void draw(sf::RenderWindow& window);

        void handleInput(sf::Event& event);

        ~Maps() {
            for (auto& npc : npcs) {
                delete npc;
            }
        }
};

#endif 
