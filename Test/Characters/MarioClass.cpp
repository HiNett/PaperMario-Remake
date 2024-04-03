#include <fstream>
#include <iostream> // Include for std::cerr
#include "../json/json.h" // Include JSON library
#include "./Character.hpp"

Mario::Mario(const std::string& name, const std::string& jsonFilename) {
    // Initialize member variables properly
    moveSpeed = 10.0f;
    movingLeft = false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
    lookingLeft = false;
    lookingRight = false;
    currentFrame = 0;
    animationSpeed = 0.5f;
    jump = false;
    jumpMaxHeight = 300.0f;
    gravity = 20.0f;
    originalXPosition = 0;
    originalYPosition = 0;

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

    const Json::Value& mario = root["mario"];
    for (const auto& marioData : mario) {
        std::string marioName = marioData["name"].asString();
        if (marioName == name) {
            // Load mario texture
            std::string texturePath = marioData["texturePath"].asString();
            if (!texture.loadFromFile(texturePath)) {
                std::cerr << "Failed to load texture: " << texturePath << std::endl;
                return;
            }

                for (int i = 0; i < 3; ++i) {
                    leftFeetRect[i].left = marioData["leftFeetFrames"][i]["left"].asInt();
                    leftFeetRect[i].top = marioData["leftFeetFrames"][i]["top"].asInt();
                    leftFeetRect[i].width = marioData["leftFeetFrames"][i]["width"].asInt();
                    leftFeetRect[i].height = marioData["leftFeetFrames"][i]["height"].asInt();

                    rightFeetRect[i].left = marioData["rightFeetFrames"][i]["left"].asInt();
                    rightFeetRect[i].top = marioData["rightFeetFrames"][i]["top"].asInt();
                    rightFeetRect[i].width = marioData["rightFeetFrames"][i]["width"].asInt();
                    rightFeetRect[i].height = marioData["rightFeetFrames"][i]["height"].asInt();
                }

                // Set the texture rectangle for Body
                sf::IntRect bodyRect;
                bodyRect.left = marioData["body"]["left"].asInt();
                bodyRect.top = marioData["body"]["top"].asInt();
                bodyRect.width = marioData["body"]["width"].asInt();
                bodyRect.height = marioData["body"]["height"].asInt();

                // Set the texture rectangle for Left Arm
                sf::IntRect leftArmRect;
                leftArmRect.left = marioData["leftArm"]["left"].asInt();
                leftArmRect.top = marioData["leftArm"]["top"].asInt();
                leftArmRect.width = marioData["leftArm"]["width"].asInt();
                leftArmRect.height = marioData["leftArm"]["height"].asInt();

                // Set the texture rectangle for Right Arm
                sf::IntRect rightArmRect;
                rightArmRect.left = marioData["rightArm"]["left"].asInt();
                rightArmRect.top = marioData["rightArm"]["top"].asInt();
                rightArmRect.width = marioData["rightArm"]["width"].asInt();
                rightArmRect.height = marioData["rightArm"]["height"].asInt();

                // Set the texture rectangle for Left Hand
                sf::IntRect leftHandRect;
                leftHandRect.left = marioData["leftHand"]["left"].asInt();
                leftHandRect.top = marioData["leftHand"]["top"].asInt();
                leftHandRect.width = marioData["leftHand"]["width"].asInt();
                leftHandRect.height = marioData["leftHand"]["height"].asInt();

                // Set the texture rectangle for Right Hand
                sf::IntRect rightHandRect;
                rightHandRect.left = marioData["rightHand"]["left"].asInt();
                rightHandRect.top = marioData["rightHand"]["top"].asInt();
                rightHandRect.width = marioData["rightHand"]["width"].asInt();
                rightHandRect.height = marioData["rightHand"]["height"].asInt();

                // Set the texture rectangle for Head
                sf::IntRect headRect;
                headRect.left = marioData["head"]["left"].asInt();
                headRect.top = marioData["head"]["top"].asInt();
                headRect.width = marioData["head"]["width"].asInt();
                headRect.height = marioData["head"]["height"].asInt();

                // Set the texture rectangles for Mario
                leftFeetSprite.setTexture(texture);
                leftFeetSprite.setTextureRect(leftFeetRect[0]);
                rightFeetSprite.setTexture(texture);
                rightFeetSprite.setTextureRect(rightFeetRect[0]);
                bodySprite.setTexture(texture);
                bodySprite.setTextureRect(bodyRect);
                leftArmSprite.setTexture(texture);
                leftArmSprite.setTextureRect(leftArmRect);
                rightArmSprite.setTexture(texture);
                rightArmSprite.setTextureRect(rightArmRect);
                leftHandSprite.setTexture(texture);
                leftHandSprite.setTextureRect(leftHandRect);
                rightHandSprite.setTexture(texture);
                rightHandSprite.setTextureRect(rightHandRect);
                headSprite.setTexture(texture);
                headSprite.setTextureRect(headRect);

            break;
        }
    }

    file.close();
}


void Mario::setPosition(float x, float y) {

    sf::Vector2f basePosition(x, y);
    int xOffSet = lookingRight ? -1 : 1;
    int bodyOffSet = lookingRight ? 50 : 0;

    leftFeetSprite.setPosition(basePosition.x + (35 * xOffSet) + bodyOffSet, basePosition.y + 135);
    rightFeetSprite.setPosition(basePosition.x + (10 * xOffSet) + bodyOffSet, basePosition.y + 135);
    bodySprite.setPosition(basePosition.x + (15 * xOffSet) + bodyOffSet, basePosition.y + 85);
    leftArmSprite.setPosition(basePosition.x + (55 * xOffSet) + bodyOffSet, basePosition.y + 90);
    rightArmSprite.setPosition(basePosition.x + (20 * xOffSet) + bodyOffSet, basePosition.y + 227);
    leftHandSprite.setPosition(basePosition.x + (53 * xOffSet) + bodyOffSet, basePosition.y + 105);
    rightHandSprite.setPosition(basePosition.x + (5 * xOffSet) + bodyOffSet, basePosition.y + 110);
    headSprite.setPosition(basePosition.x - (5 * xOffSet) + bodyOffSet, basePosition.y + 5);
}

void Mario::update() {
    // Handle right / left movement
    if (movingLeft || movingRight) {
        float xMovement = 0.0f;
        if (movingLeft){
            xMovement -= moveSpeed;
        }
        if (movingRight){
            xMovement += moveSpeed;
        }
        xPosition += xMovement;
        setPosition(xPosition, yPosition);
    }

    // Jumping logic
    if (movingUp) {
        yPosition -= gravity;
        if (originalYPosition - yPosition >= jumpMaxHeight) {
            // std::cout << "result :" << originalYPosition - yPosition << std::endl;
            movingUp = false; // Stop moving upwards once maximum height is reached
        }
    } else if (!jump && !movingUp) {
        // Falling logic
        yPosition += gravity;
        // Ensure Mario does not fall below the ground level
        if (yPosition >= 800) {
            yPosition = 800;
            jump = true; // Mario touches the ground, allow jumping again
        }
    }
    // Set the new position of Mario
    setPosition(xPosition, yPosition);

    float xOffSet = lookingRight ? -1.0f : 1.0f;   
    leftFeetSprite.setScale(xOffSet, 1.0f);
    rightFeetSprite.setScale(xOffSet, 1.0f);
    bodySprite.setScale(xOffSet, 1.0f);
    leftArmSprite.setScale(xOffSet, 1.0f);
    rightArmSprite.setScale(xOffSet, 1.0f);
    leftHandSprite.setScale(xOffSet, 1.0f);
    rightHandSprite.setScale(xOffSet, 1.0f);
    headSprite.setScale(xOffSet, 1.0f);

    if ((movingLeft || movingRight) && animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        int currentLeftFeetFrame = (currentFrame + 1) % 3;
        int currentRightFeetFrame = (currentFrame + 1) % 3;
        leftFeetSprite.setTextureRect(leftFeetRect[currentLeftFeetFrame]);
        rightFeetSprite.setTextureRect(rightFeetRect[currentRightFeetFrame]);
        animationClock.restart();
    }
    
}

void Mario::draw(sf::RenderWindow& window) const {
    // Draw all the parts
    window.draw(rightArmSprite);
    window.draw(rightHandSprite);
    window.draw(rightFeetSprite);
    window.draw(bodySprite);
    window.draw(leftFeetSprite);
    window.draw(leftArmSprite);
    window.draw(leftHandSprite);
    window.draw(headSprite);
}

void Mario::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left && !movingRight) {
            movingLeft = true;     
            lookingLeft = true;       
            movingRight = false;
            lookingRight = false;
        }
        if (event.key.code == sf::Keyboard::Right && !movingLeft) {
            movingLeft = false;
            lookingLeft = false;
            movingRight = true;
            lookingRight = true;
        }
        if (event.key.code == sf::Keyboard::Space && jump) {
            originalYPosition = yPosition;
            movingUp = true;
            movingDown = false;
            jump = false;
        }
        // Handle other movement input here
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left){
            movingLeft = false;
            // Ensure that only one direction is active at a time
            if (!movingRight) {
                movingRight = false;
            }
        }
        else if (event.key.code == sf::Keyboard::Right){
            movingRight = false;
            // Ensure that only one direction is active at a time
            if (!movingLeft) {
                movingLeft = false;
            }
        }
        else if (event.key.code == sf::Keyboard::Space){
            movingUp = false;
            movingDown = true;
        }

        // Handle other movement release here
    }
}