#inlcude "Food.h"

Food::Food(GameMechs& gameMechanics)
{
    foodPos.x = 0;
    foodPos.y = 0;
    foodPos.symbol = 'p';
    mechRef = &gameMechanics;
}

void generateFood(objPosArrayList &blockOff)
{
    int randomX;
    int randomY;

    srand(static_cast<unsigned int>(time(nullptr)));

    do
    {
        //set boolean variable for determining whether position is valid
        okPos = true;

        //randomly generate x and y coordinates
        randomX = rand() % ((mechRef -> getBoardSizeX()) - 2) + 1; 
        randomY = rand() % ((mechRef -> getBoardSizeY()) - 2) + 1;

        // iterate through the blockOff list to determine any conflicts between the current and previous position
        for(int i = 0; i < blockOff.getSize(); ++i)
        {
            // create tempPosition as an objPos datatype
            objPos tempPosition;

            //store the value of each i into tempPosition
            blockOff.getElement(i, tempPosition);

            // check if that indexes value matches with the random positions generated
            if(tempPosition.x == randomX && tempPosition.y == randomY)
            {
                //if it matches, flag that the position is not correct and reenter the dowhile loop
                okPos = false;
                // no need to check if the next index is invalid if the current one is
                break;
            }

        } 

    }while (!okPos);

    foodPos.x = randomX;
    foodPos.y = randomY;

  
}
