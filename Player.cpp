#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5,5, '0')
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol)
    
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    //Check if this is to correct input
    switch (mainGameMechsRef.getInput())
    {
    case 'w':
        if (myDir!= UP && myDir != DOWN)
            Dir = UP;
        break;
    case 'W':
        if (myDir!= UP && myDir != DOWN)
            Dir = UP;
        break;
    case 's':
        if (myDir!= UP && myDir != DOWN)
            Dir = DOWN;
        break;
    case 'S':
        if (myDir!= UP && myDir != DOWN)
            Dir = DOWN;
        break;
    case 'a':
        if (myDir!= LEFT && myDir != RIGHT)
            myFSMMode = LEFT;
        break;
    case 'A':
        if (myDir!= LEFT && myDir != RIGHT)
            myFSMMode = LEFT;
        break;
    case 'd':
        if (myDir!= LEFT && myDir != RIGHT)
            myFSMMode = RIGHT;
        break;
    case 'D':
        if (myDir!= LEFT && myDir != RIGHT)
            myFSMMode = RIGHT;
        break;
    default:
        break;
    }
            
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    
}

