// Maps.hpp
#ifndef MAPS_HPP
#define MAPS_HPP

#include <SFML/Graphics.hpp>
#include "MarioClass.hpp"
#include "HammerBrosClass.hpp"
#include <vector>
#include <json/json.h> // Include your JSON library, like JsonCpp

class Maps {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Mario mario;
    HammerBros hammerBros;

    // Vector to store other map elements if needed

public:
    Maps();
    void initializeBackgroundFromJSON(const std::string& filename);
    void initializeCharactersFromJSON(const std::string& filename);
    void update();
    void draw(sf::RenderWindow& window);
};

#endif 
