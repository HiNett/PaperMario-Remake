// Maps.hpp
#ifndef MAPS_HPP
#define MAPS_HPP

#include <SFML/Graphics.hpp>
#include "../Characters/MarioClass.cpp"
#include "../Characters/HammerBrosClass.cpp"
#include <vector>

class Maps {
    private:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

    public:
        // Arguments
        string name;
        string background;
        float ground_height;
        
        // Methods
        Maps();
        void loadMapData(const std::string& filename);
        void update();
        void draw(sf::RenderWindow& window);
};

#endif 
