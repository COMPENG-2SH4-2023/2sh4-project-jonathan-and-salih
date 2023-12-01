#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = NULL;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = NULL;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
/* 
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeY; i++)
    {
        delete [] gameBoard[i];
    }
    delete [] gameBoard;
}
*/

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}


char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();        
    }
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


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    this_input = input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

