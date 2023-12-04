#include "GameMechs.h"
#include "MacUILib.h"

#define DEFAULT_GRID_LENGTH 20
#define DEFAULT_GRID_HEIGHT 10

GameMechs::GameMechs() : GameMechs(DEFAULT_GRID_LENGTH, DEFAULT_GRID_HEIGHT){}; // default sizes, 20x10

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;

    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;

    generateFood();
}

// do you need a destructor?
// nah bro, no heap elements


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::getFoodPos(objPos &returnPos){
    returnPos = foodPos;
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::generateFood(objPosArrayList &invalidPositions){
    int generatedX, generatedY;

    // generate until valid combination is found
    while (1){
        generatedX = (rand() % (boardSizeX - 2)) + 1; // [1, 19]
        generatedY = (rand() % (boardSizeY - 2)) + 1; // [1, 9]

        // check if collides with snake body/any invalid items
        if (invalidPositions.find(generatedX, generatedY) == -1){ // -1 means no matches inside invalidPOsitions 
            foodPos = objPos(generatedX, generatedY, 'O');
            return;
        }

    }
}

void GameMechs::generateFood(){
    int generatedX, generatedY;

    generatedX = (rand() % (boardSizeX - 2)) + 1; // [1, 19]
    generatedY = (rand() % (boardSizeY - 2)) + 1; // [1, 9]

    foodPos = objPos(generatedX, generatedY, 'O');
}

void GameMechs::incrementScore(){
    score ++;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

