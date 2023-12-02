#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
Food* myFood;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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
    
    myGM = new GameMechs(26,13);
    myPlayer = new Player(myGM);
    myFood= new Food(*myGM);
    objPosArrayList blockOff;
    myFood->generateFood(blockOff);

    
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();


    objPosArrayList blockOff;
    myFood->generateFood(blockOff);
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos playerPos;
    myPlayer->getPlayerPos(playerPos);

    objPos foodPos;
    myFood->getFoodPos(foodPos);

    /*
    objPosArrayList* temPos2;
    myFood->generateFood(temPos2);*/

    for(int i=0; i < myGM->getBoardSizeY(); i++)
    {
        // print bottom and top border 
        for(int k=0; k < myGM->getBoardSizeX()+1; k++)
        {
            //print top and bottom border
            if(i == myGM->getBoardSizeY()-1 || i == 0)
            {
                MacUILib_printf("#");
            }

            //print right and left border
            if(i > 0 && i < myGM->getBoardSizeY()-1)
            {
                if(k == myGM->getBoardSizeX()-1 || k==0)
                {
                    MacUILib_printf("#"); 
                }

                if (k == playerPos.x && i== playerPos.y)
                {
                MacUILib_printf("%c", playerPos.symbol);
                }
                else if(k == foodPos.x && i== foodPos.y)
                {

                    MacUILib_printf("%c", foodPos.symbol);
                }
                else
                {
                    MacUILib_printf(" ");                    
                }   
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("board %d,%d | player %d,%d | symbol %c",
                    myGM->getBoardSizeX(), myGM->getBoardSizeY(),
                    playerPos.x,playerPos.y,playerPos.symbol);
    MacUILib_printf(" input: %c", myGM->getInput());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
