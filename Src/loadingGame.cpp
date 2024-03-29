#ifndef loadingGame_CPP
#define loadingGame_CPP

#include <iostream>
#include <fstream>
#include <string>
using std::string;



string character, items;
int lifePoints, powerPoints, defensePoints, yPosition, xPosition, experiencePoints, level, flowerPoints, badgePoints, kamas, jump;

int loadingGame()
{
    string line;
    std::ifstream file("load.txt");
    if (file.is_open())
    {
        // Put each line in a variable
        // First line is character, then lifePoints, powerPoints, etc etc
        getline(file, character);
        getline(file, line);
        lifePoints = std::stoi(line);
        getline(file, line);
        powerPoints = std::stoi(line);
        getline(file, line);
        defensePoints = std::stoi(line);
        getline(file, line);
        yPosition = std::stoi(line);
        getline(file, line);
        xPosition = std::stoi(line);
        getline(file, line);
        experiencePoints = std::stoi(line);
        getline(file, line);
        level = std::stoi(line);
        getline(file, line);
        flowerPoints = std::stoi(line);
        getline(file, line);
        badgePoints = std::stoi(line);
        getline(file, line);
        kamas = std::stoi(line);
        getline(file, line);
        jump = std::stoi(line);
        getline(file, items);
        
        file.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
    std::cout << "Character: " << character << std::endl;
    std::cout << "Life Points: " << lifePoints << std::endl;
    std::cout << "Power Points: " << powerPoints << std::endl;
    std::cout << "Defense Points: " << defensePoints << std::endl;
    std::cout << "Y Position: " << yPosition << std::endl;
    std::cout << "X Position: " << xPosition << std::endl;
    std::cout << "Experience Points: " << experiencePoints << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Flower Points: " << flowerPoints << std::endl;
    std::cout << "Badge Points: " << badgePoints << std::endl;
    std::cout << "Kamas: " << kamas << std::endl;
    std::cout << "Jump: " << jump << std::endl;
    std::cout << "Items: " << items << std::endl;
    return 0;
}

#endif