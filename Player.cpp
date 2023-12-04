#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = new objPosArrayList();
    playerPos->insertHead({10, 5, '*'}); // insert starting element
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPosArrayList &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos = *playerPos;
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

    input = 0; // reset input to nothing after processing action

}

void Player::movePlayer(bool deleteTailElem = true)
{
    // the next position the snake head will be, init to current head to calculate next position
    objPos next;
    playerPos->getHeadElement(next);

    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            next.x --;
            break;

        case RIGHT:
            next.x ++;
            break;

        case UP:
            next.y --;
            break;

        case DOWN:
            next.y ++;
            break;

        default:
            break;
    }

    // border wraparound vars
    int boardX, boardY;

    boardX =  mainGameMechsRef->getBoardSizeX();
    boardY =  mainGameMechsRef->getBoardSizeY();
    
    // check for border wraparound
    // top side border
    if (next.y == 0){
        next.y = boardY - 2;
    }
    // bottom side border
    else if (next.y == boardY - 1){
        next.y = 1;
    }
    // left side border
    else if (next.x == 0){
        next.x = boardX - 2;
    }
    // right side border
    else if (next.x == boardX - 1){
        next.x = 1;
    }

    // MacUILib_printf("state before:\n");
    // objPos a;
    // for (int i = 0; i < playerPos->getSize(); i ++){
    //     playerPos->getElement(a, i);
    //     MacUILib_printf("position(x,y): %d %d ", a.x, a.y);
    // }

    // add the new element to array at front
    playerPos->insertHead(next);

    // delete the tail if food was not collected
    if (deleteTailElem){
        playerPos->removeTail();
    }

    // MacUILib_printf("\nstate after:\n");
    // for (int i = 0; i < playerPos->getSize(); i ++){
    //     playerPos->getElement(a, i);
    //     MacUILib_printf("position(x,y): %d %d ", a.x, a.y);
    // }

    // MacUILib_printf("\n");
}

bool Player::checkForFutureCollision(objPos position){
    // the next position the snake head will be, init to current head to calculate next position
    objPos next;
    playerPos->getHeadElement(next);

    // PPA3 Finite State Machine logic
    switch(myDir){

        case LEFT:
            next.x --;
            break;

        case RIGHT:
            next.x ++;
            break;

        case UP:
            next.y --;
            break;

        case DOWN:
            next.y ++;
            break;

        default:
            break;
    }

    // border wraparound vars
    int boardX, boardY;

    boardX =  mainGameMechsRef->getBoardSizeX();
    boardY =  mainGameMechsRef->getBoardSizeY();
    
    // check for border wraparound
    // top side border
    if (next.y == 0){
        next.y = boardY - 2;
    }
    // bottom side border
    else if (next.y == boardY - 1){
        next.y = 1;
    }
    // left side border
    else if (next.x == 0){
        next.x = boardX - 2;
    }
    // right side border
    else if (next.x == boardX - 1){
        next.x = 1;
    }

    // check if will collide with position
    if (next.x == position.x && next.y == position.y){
        return true;
    }
    return false;
}