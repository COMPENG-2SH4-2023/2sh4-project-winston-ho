#ifndef PLAYER_H
#define PLAYER_H

#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPosArrayList &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir(); 
        // deleteTailElem : bool. Optional, default=true. should supply false when snake is fed food to not destroy old data
        void movePlayer(bool deleteTailElem);

        // does not modify anyhting. simply moves forward 1 space, then check if it would collide with the position
        bool checkForFutureCollision(objPos position);

    private:
        objPosArrayList* playerPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif