#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

// define classes for use in program
Player *player;
GameMechs *game;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // create classes
    game = new GameMechs();
    player = new Player(game); // use previously created GameMechs class to init Player class to sync them together
}

void GetInput(void)
{
   bool isInput; // is there an input?

    // check if there is input
    isInput = MacUILib_hasChar();

    // if there is input, read and save the character
    if (isInput){
        // MacUILib_printf("setting input\n");
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

    // check if on food position
    objPos foodPos, playerPos; 
    player->getPlayerPos(playerPos);
    game->getFoodPos(foodPos);

    // regenerate food and increment score if food touched
    if (foodPos.x == playerPos.x && foodPos.y == playerPos.y){
        game->generateFood();
        game->incrementScore();
    }
}

void DrawScreen(void)
{
    // define vars
    int row, col; // looping vars
    int boardX, boardY; // size of the x/y of the grid

    objPos playerData, foodPos;

    // get inital information
    player->getPlayerPos(playerData);
    game->getFoodPos(foodPos);

    boardX = game->getBoardSizeX();
    boardY = game->getBoardSizeY();

    // clear the current screen contents
    MacUILib_clearScreen();

    // display the grid
    for (row = 0; row < boardY; row ++){
        for (col = 0; col < boardX; col ++){

            // check for character
            if (playerData.x == col && playerData.y == row){
                MacUILib_printf("%c", playerData.symbol);
            }
            // check if wall
            else if ((row == 0) || (row == boardY - 1) || (col == 0) || (col == boardX - 1)){
                MacUILib_printf("#");
            }
            // TODO: check if food
            else if (foodPos.x == col && foodPos.y == row){
                MacUILib_printf("%c", foodPos.symbol);
            }
            // else, print a space
            else {
                MacUILib_printf(" ");
            }
            
        }
        // format each line
        MacUILib_printf("\n");
    }

    // reset data for next iteration
    game->clearInput();

    // DEBUG
    MacUILib_printf("score, %d\n", game->getScore());
    MacUILib_printf("playerData.x: %d, playerData.y: %d\n", playerData.x, playerData.y);
    MacUILib_printf("foodPos.x: %d, foodPos.y: %d\n", foodPos.x, foodPos.y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
    // MacUILib_Delay(999999);
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // dealloc heap elements
    delete player;
    delete game;
}
