#include "Player.h"

// define a default constructor that is invalid, so that c++ doesnt throw an errors
Player::Player(){
}

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = objPos(5, 10, '*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos = playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    // figure out which direction to set the player position to now
    switch(input){              

        case ' ':  // exit
            mainGameMechsRef->setExitTrue();
            myDir = STOP;
            break;
        // Add more key processing here
        case 'W':
        case 'w':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){ // only switch direction if direction is STOP or adjacent to current DIR
                myDir = UP;
            }
            break;
        // Add more key processing here
        case 'S':
        case 's':
            if (myDir == LEFT || myDir == RIGHT || myDir == STOP){ // only switch direction if direction is STOP or adjacent to current DIR
                myDir = DOWN;
            }
            break;
        // Add more key processing here
        case 'D':
        case 'd':
            if (myDir == UP || myDir == DOWN || myDir == STOP){ // only switch direction if direction is STOP or adjacent to current DIR
                myDir = RIGHT;
            }
            break;
        // Add more key processing here
        case 'A':
        case 'a':
            if (myDir == UP || myDir == DOWN || myDir == STOP){ // only switch direction if direction is STOP or adjacent to current DIR
                myDir = LEFT;
            }
            break;

        default: // do nothing if no match
            break;
    }

    input = NULL; // reset input to nothing after processing action
}

void Player::movePlayer()
{

    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            playerPos.x --;
            break;

        case RIGHT:
            playerPos.x ++;
            break;

        case UP:
            playerPos.y --;
            break;

        case DOWN:
            playerPos.y ++;
            break;

        default:
            break;
    }
}

