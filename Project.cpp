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
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();
}

void DrawScreen(void)
{
    // define vars
    int row, col; // looping vars
    int boardX, boardY; // size of the x/y of the grid

    objPos playerData;

    // get inital information
    player->getPlayerPos(playerData);

    boardX = game->getBoardSizeX();
    boardY = game->getBoardSizeY();

    // clear the current screen contents
    MacUILib_clearScreen();

    // // display the grid
    // for (row = 0; row < boardY; row ++){
    //     for (col = 0; col < boardX; col ++){

    //         // check for character
    //         if (playerData.x == col && playerData.y == row){
    //             MacUILib_printf("%c", playerData.symbol);
    //         }
    //         // check if wall
    //         else if ((row == 0) || (row == boardX - 1) || (col == 0) || (col == boardY - 1)){
    //             MacUILib_printf("#");
    //         }
    //         // TODO: check if food
    //         // else, print a space
    //         else {
    //             MacUILib_printf(" ");
    //         }
            
    //     }
    //     // format each line
    //     MacUILib_printf("\n");
    // }

    // reset data for next iteration
    game->clearInput();

    // DEBUG
    MacUILib_printf("game->getExitFlagStatus(), %d\n", game->getExitFlagStatus());
    MacUILib_printf("boardY: %d, boardX: %d\n", boardY, boardX);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // dealloc heap elements
    delete player;
    delete game;
}
