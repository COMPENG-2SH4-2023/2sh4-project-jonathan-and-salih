#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    myFood = thisFood;

    // more actions to be included
    playerPosList = new objPosArrayList();
    
    objPos startPos(mainGameMechsRef->getBoardSizeX() / 2 ,
                        mainGameMechsRef->getBoardSizeY() / 2 ,
                         '0');
    playerPosList->insertHead(startPos);
    
    for (int i = 1; i < 4; i++)
    {
        objPos nextPos(startPos.x + i, startPos.y, '0');
        playerPosList->insertTail(nextPos);
    }
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
    
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
    objPos playerPos;
    playerPosList->getHeadElement(playerPos);
    //objPos playerPos = headPos;
    

    switch(myDir){
    case LEFT:
        playerPos.x--;
        if (playerPos.x == -1)
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
    if(checkFoodConsumption())
    {
        //insert head
        playerPosList->insertHead(playerPos);
        //generate new food
        objPosArrayList blockOff;
        myFood->generateFood(blockOff);
    }
    else
    {
        //insert head and remove tail aka moving
        playerPosList->insertHead(playerPos);
        playerPosList->removeTail();
    }

}


bool Player::checkFoodConsumption()
{
    //if food is in the same position as head reaturn true
    objPos playerPos;
    playerPosList->getHeadElement(playerPos);
    objPos foodPos;
    myFood->getFoodPos(foodPos);
    if (foodPos.x == playerPos.x && foodPos.y == playerPos.y)
        return true;
    else
        return false;

}
void Player::increasePlayerLength()
{}
bool Player::checkSelfCollision()
{

}