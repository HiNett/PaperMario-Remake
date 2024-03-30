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

    if (!marioTexture.loadFromFile("../Assets/Sprites/MarioSprites.png")) {
        return;
    }

    marioLeftFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    marioLeftFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    marioLeftFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    marioRightFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    marioRightFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    marioRightFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    marioBody = sf::IntRect(1079, 1834, 57, 59);
    marioLeftArm = sf::IntRect(1666, 1588, 29, 51);
    marioRightArm = sf::IntRect(0, 0, 0, 0); 
    marioLeftHand = sf::IntRect(1564, 1918, 39, 39);
    marioRightHand = sf::IntRect(1209, 2206, 40, 41);
    marioHead = sf::IntRect(1067, 1507, 101, 92);
    loadTexture();
}

void Mario::setPosition(float x, float y) {

    sf::Vector2f basePosition(x, y);
    int xOffSet = lookingRight ? -1 : 1;
    int bodyOffSet = lookingRight ? 50 : 0;

    marioLeftFeetSprite.setPosition(basePosition.x + (35 * xOffSet) + bodyOffSet, basePosition.y + 135);
    marioRightFeetSprite.setPosition(basePosition.x + (10 * xOffSet) + bodyOffSet, basePosition.y + 135);
    marioBodySprite.setPosition(basePosition.x + (15 * xOffSet) + bodyOffSet, basePosition.y + 85);
    marioLeftArmSprite.setPosition(basePosition.x + (55 * xOffSet) + bodyOffSet, basePosition.y + 90);
    marioRightArmSprite.setPosition(basePosition.x + (20 * xOffSet) + bodyOffSet, basePosition.y + 227);
    marioLeftHandSprite.setPosition(basePosition.x + (53 * xOffSet) + bodyOffSet, basePosition.y + 105);
    marioRightHandSprite.setPosition(basePosition.x + (5 * xOffSet) + bodyOffSet, basePosition.y + 110);
    marioHeadSprite.setPosition(basePosition.x - (5 * xOffSet) + bodyOffSet, basePosition.y + 5);
}

void Mario::loadTexture() {

    marioLeftFeetSprite.setTexture(marioTexture);
    marioLeftFeetSprite.setTextureRect(marioLeftFeetFrames[0]); 
    marioRightFeetSprite.setTexture(marioTexture);
    marioRightFeetSprite.setTextureRect(marioRightFeetFrames[0]); 
    marioBodySprite.setTexture(marioTexture);
    marioBodySprite.setTextureRect(marioBody);
    marioLeftArmSprite.setTexture(marioTexture);
    marioLeftArmSprite.setTextureRect(marioLeftArm);
    marioRightArmSprite.setTexture(marioTexture);
    marioRightArmSprite.setTextureRect(marioRightArm);
    marioLeftHandSprite.setTexture(marioTexture);
    marioLeftHandSprite.setTextureRect(marioLeftHand);
    marioRightHandSprite.setTexture(marioTexture);
    marioRightHandSprite.setTextureRect(marioRightHand);
    marioHeadSprite.setTexture(marioTexture);
    marioHeadSprite.setTextureRect(marioHead);
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
        // Move Mario upward by jumpSpeed
        yPosition -= gravity;
        // Check if Mario has reached the maximum jump height
        if (originalYPosition - yPosition >= jumpMaxHeight) {
            std::cout << "result :" << originalYPosition - yPosition << std::endl;
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
    marioLeftFeetSprite.setScale(xOffSet, 1.0f);
    marioRightFeetSprite.setScale(xOffSet, 1.0f);
    marioBodySprite.setScale(xOffSet, 1.0f);
    marioLeftArmSprite.setScale(xOffSet, 1.0f);
    marioRightArmSprite.setScale(xOffSet, 1.0f);
    marioLeftHandSprite.setScale(xOffSet, 1.0f);
    marioRightHandSprite.setScale(xOffSet, 1.0f);
    marioHeadSprite.setScale(xOffSet, 1.0f);

    if ((movingLeft || movingRight) && animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        int currentLeftFeetFrame = (currentFrame + 1) % 3;
        int currentRightFeetFrame = (currentFrame + 1) % 3;
        marioLeftFeetSprite.setTextureRect(marioLeftFeetFrames[currentLeftFeetFrame]);
        marioRightFeetSprite.setTextureRect(marioRightFeetFrames[currentRightFeetFrame]);
        animationClock.restart();
    }
    
}

void Mario::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(marioRightArmSprite);
    window.draw(marioRightHandSprite);
    window.draw(marioRightFeetSprite);
    window.draw(marioBodySprite);
    window.draw(marioLeftFeetSprite);
    window.draw(marioLeftArmSprite);
    window.draw(marioLeftHandSprite);
    window.draw(marioHeadSprite);
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
