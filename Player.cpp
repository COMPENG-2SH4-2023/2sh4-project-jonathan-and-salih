#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = UP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2 ,
                        mainGameMechsRef->getBoardSizeY() / 2 ,
                         '0');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    //Check if this is to correct input
    switch (mainGameMechsRef->getInput())
    {
    case 'w':
        if (myDir!= UP && myDir != DOWN)
            myDir = UP;
        break;
    case 'W':
        if (myDir!= UP && myDir != DOWN)
            myDir = UP;
        break;
    case 's':
        if (myDir!= UP && myDir != DOWN)
            myDir = DOWN;
        break;
    case 'S':
        if (myDir!= UP && myDir != DOWN)
            myDir = DOWN;
        break;
    case 'a':
        if (myDir!= LEFT && myDir != RIGHT)
            myDir = LEFT;
        break;
    case 'A':
        if (myDir!= LEFT && myDir != RIGHT)
            myDir = LEFT;
        break;
    case 'd':
        if (myDir!= LEFT && myDir != RIGHT)
            myDir = RIGHT;
        break;
    case 'D':
        if (myDir!= LEFT && myDir != RIGHT)
            myDir = RIGHT;
        break;
    default:
        break;
    }
            
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir){
    case LEFT:
        playerPos.x--;
        if (playerPos.x == 0)
            playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
        break;
    case RIGHT:
        playerPos.x++;
        if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1)
            playerPos.x = 1;
        break;
    case UP:
        playerPos.y--;
        if (playerPos.y == 0)
            playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
        break;
    case DOWN:
        playerPos.y++;
        if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1)
            playerPos.y = 1;
        break;
    default:
        break;
    }
}

