#ifndef ITEM_HPP
#define ITEM_HPP

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Item {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    sf::IntRect mushroomRect;
    sf::IntRect superMushroomRect;
    sf::IntRect sirupRect;
    sf::IntRect superSirupRect;
    
    int id;
    string name;
    int kamas;
    string description;
    bool useInCombatOnly;
    int lifePoint;
    int flowerPoint;

    // Methods
    Item();
    void setPosition(float x, float y);
    virtual void draw(sf::RenderWindow& window);
};

vector<Item> initializeItems();

#endif
