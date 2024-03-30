#include "./Class.hpp"

Mario::Mario() {
    moveSpeed = 10.0f;
    movingLeft = false;
    movingRight = false;
    movingUp;
    movingDown;
    lookingLeft;
    lookingRight;
    currentFrame = 0;
    animationClock;
    animationSpeed = 0.5f;
    jump;
    jumpMaxHeight = 300.0f;
    gravity = 20.0f;
    originalXPosition;
    originalYPosition;

    if (!texture.loadFromFile("../Assets/Sprites/MarioSprites.png")) {
        return;
    }

    LeftFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    LeftFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    LeftFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    RightFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    RightFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    RightFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    Body = sf::IntRect(1079, 1834, 57, 59);
    LeftArm = sf::IntRect(1666, 1588, 29, 51);
    RightArm = sf::IntRect(0, 0, 0, 0); 
    LeftHand = sf::IntRect(1564, 1918, 39, 39);
    RightHand = sf::IntRect(1209, 2206, 40, 41);
    Head = sf::IntRect(1067, 1507, 101, 92);
    loadTexture();
}

void Mario::setPosition(float x, float y) {

    sf::Vector2f basePosition(x, y);
    int xOffSet = lookingRight ? -1 : 1;
    int bodyOffSet = lookingRight ? 50 : 0;

    LeftFeetSprite.setPosition(basePosition.x + (35 * xOffSet) + bodyOffSet, basePosition.y + 135);
    RightFeetSprite.setPosition(basePosition.x + (10 * xOffSet) + bodyOffSet, basePosition.y + 135);
    BodySprite.setPosition(basePosition.x + (15 * xOffSet) + bodyOffSet, basePosition.y + 85);
    LeftArmSprite.setPosition(basePosition.x + (55 * xOffSet) + bodyOffSet, basePosition.y + 90);
    RightArmSprite.setPosition(basePosition.x + (20 * xOffSet) + bodyOffSet, basePosition.y + 227);
    LeftHandSprite.setPosition(basePosition.x + (53 * xOffSet) + bodyOffSet, basePosition.y + 105);
    RightHandSprite.setPosition(basePosition.x + (5 * xOffSet) + bodyOffSet, basePosition.y + 110);
    HeadSprite.setPosition(basePosition.x - (5 * xOffSet) + bodyOffSet, basePosition.y + 5);
}

void Mario::loadTexture() {

    LeftFeetSprite.setTexture(texture);
    LeftFeetSprite.setTextureRect(LeftFeetFrames[0]); 
    RightFeetSprite.setTexture(texture);
    RightFeetSprite.setTextureRect(RightFeetFrames[0]); 
    BodySprite.setTexture(texture);
    BodySprite.setTextureRect(Body);
    LeftArmSprite.setTexture(texture);
    LeftArmSprite.setTextureRect(LeftArm);
    RightArmSprite.setTexture(texture);
    RightArmSprite.setTextureRect(RightArm);
    LeftHandSprite.setTexture(texture);
    LeftHandSprite.setTextureRect(LeftHand);
    RightHandSprite.setTexture(texture);
    RightHandSprite.setTextureRect(RightHand);
    HeadSprite.setTexture(texture);
    HeadSprite.setTextureRect(Head);
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
    LeftFeetSprite.setScale(xOffSet, 1.0f);
    RightFeetSprite.setScale(xOffSet, 1.0f);
    BodySprite.setScale(xOffSet, 1.0f);
    LeftArmSprite.setScale(xOffSet, 1.0f);
    RightArmSprite.setScale(xOffSet, 1.0f);
    LeftHandSprite.setScale(xOffSet, 1.0f);
    RightHandSprite.setScale(xOffSet, 1.0f);
    HeadSprite.setScale(xOffSet, 1.0f);

    if ((movingLeft || movingRight) && animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        int currentLeftFeetFrame = (currentFrame + 1) % 3;
        int currentRightFeetFrame = (currentFrame + 1) % 3;
        LeftFeetSprite.setTextureRect(LeftFeetFrames[currentLeftFeetFrame]);
        RightFeetSprite.setTextureRect(RightFeetFrames[currentRightFeetFrame]);
        animationClock.restart();
    }
    
}

void Mario::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(RightArmSprite);
    window.draw(RightHandSprite);
    window.draw(RightFeetSprite);
    window.draw(BodySprite);
    window.draw(LeftFeetSprite);
    window.draw(LeftArmSprite);
    window.draw(LeftHandSprite);
    window.draw(HeadSprite);
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
