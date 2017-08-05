//
// Created by ju5t1nas on 2017-08-04.
//

#include "board.h"
#include "GLogLinkedList.h"

void board::fillMainBoard(int inputBoard[3][3][3][3])
{
    for(int i = 0; i < 3; i+=1)
    {
        for(int j = 0; j < 3; j+=1)
        {
            for(int k = 0; k < 3; k+=1)
            {
                for(int l = 0; l < 3; l+=1)
                {
                    mainBoard[i][j][k][l] = inputBoard[i][j][k][l];
                }

            }
        }
    }
}

void board::fillPossibilityBoard()
{
    for(int i = 0; i < 3; i+=1)
    {
        for(int j = 0; j < 3; j+=1)
        {
            for(int k = 0; k < 3; k+=1)
            {
                for(int l = 0; l < 3; l+=1)
                {
                    if(mainBoard[i][j][k][l] != 0)
                    {
                        for(int m = 0; m < 10; m+=1)
                        {
                            if(m != mainBoard[i][j][k][l])
                            {
                                possibilityBoard[i][j][k][l][m] = 0;
                            }
                            else if(m == mainBoard[i][j][k][l])
                            {
                                possibilityBoard[i][j][k][l][m] = 1;
                            }
                        }
                    }
                    else if(mainBoard[i][j][k][l] == 0)
                    {
                        for(int m = 0; m < 10; m += 1)
                        {
                            possibilityBoard[i][j][k][l][m] = 1;
                        }
                    }
                }
            }
        }
    }
}

bool board::checkIfFilled()
{
    for(int i = 0; i < 3; i+=1)
    {
        for(int j = 0; j < 3; j+=1)
        {
            for(int k = 0; k < 3; k+=1)
            {
                for(int l = 0; l < 3; l+=1)
                {
                    if(mainBoard[i][j][k][l] == 0)
                    {
                        std::cout << "Not Filled" << std::endl;
                        return false;
                    }
                }

            }
        }
    }
    std::cout << "Filled" << std::endl;
    return true;
}

void board::makeChoice()
{
    int lowestNum = 10;
    int lowestCoor[4];

    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int k=0; k<=3; k+=1)
            {
                for(int l=0; l<=3; l+=1)
                {
                    int counter = 0;
                    if(possibilityBoard[i][j][k][l][0] != 0)
                    {
                        for(int m=1; m<10; m+=1)
                        {
                            if(possibilityBoard[i][j][k][l][m] != 0)
                            {
                                counter += 1;
                            }
                        }
                        if(counter < lowestNum and counter != 0)
                        {
                            lowestNum = counter;

                            lowestCoor[0] = i;
                            lowestCoor[1] = j;
                            lowestCoor[2] = k;
                            lowestCoor[3] = l;
                        }
                    }
                }
            }
        }
    }

    guess(lowestCoor, lowestNum);


}

void board::guess(int coordinates[4], int priority)
{
    int numberGuessed = 0;

    for(int i = 1; i<10; i+=1)
    {
        if(possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][i] != 0)
        {
            numberGuessed = i;
            break;
        }
    }

    guesses.add_node(coordinates, numberGuessed, priority, possibilityBoard, mainBoard);

    mainBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]] = numberGuessed;
}

void board::possibilityBoardPass()
{
    for(int i = 0; i<3; i+=1)
    {
        for(int j = 0; j<3; j+=1)
        {
            for(int k = 0; k<3; k+=1)
            {
                for(int l = 0; l<3; l+=1)
                {
                    int coordinates[4] = {i, j, k, l};
                    findPossibilities(coordinates);
                }
            }
        }
    }
}

void board::findPossibilities(int coordinates[4])
{

    //Checking horizontally
    if(possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][0] != 0){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                //std::cout << mainBoard[coordinates[0]][i][coordinates[2]][j];
                if(mainBoard[coordinates[0]][i][coordinates[2]][j] != 0){
                    possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][mainBoard[coordinates[0]][i][coordinates[2]][j]] = 0;
                }
            }
        }
        //std::cout << std::endl;
    }


    //Checking vertically
    if(possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][0] != 0){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                //std::cout << mainBoard[i][coordinates[1]][j][coordinates[3]];
                if(mainBoard[i][coordinates[1]][j][coordinates[3]] != 0){
                    possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][mainBoard[i][coordinates[1]][j][coordinates[3]]] = 0;
                }
            }
        }
        //std::cout << std::endl;
    }


    //Checking the box
    if(possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][0] != 0){
        for(int i=0; i<3; i+=1){
            for(int j=0; j<3; j+=1){
                //std::cout << mainBoard[coordinates[0]][coordinates[1]][i][j];
                if(mainBoard[coordinates[0]][coordinates[1]][i][j] != 0){
                    possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][mainBoard[coordinates[0]][coordinates[1]][i][j]] = 0;
                }
            }
        }
        //std::cout << std::endl;
    }

    //std::cout << "[ ";
    for(int i=0; i<10; i+=1){
        //std::cout << possibilityBoard[coordinates[0]][coordinates[1]][coordinates[2]][coordinates[3]][i] << ",";
    }
    //std::cout << " ]" << std::endl;
}

void board::findAndFixMistakes()
{
    bool mistake = false;
    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int k=0; k<3; k+=1)
            {
                for(int l=0; l<3; l+=1)
                {
                    if(possibilityBoard[i][j][k][l][0] != 0)
                    {
                        int count = 0;

                        for(int m=1; m<10; m+=1)
                        {
                            if(possibilityBoard[i][j][k][l][m] != 0)
                            {
                                count += 1;
                            }
                        }

                        if(count == 0)
                        {
                            std::cout << "[" << i << "," << j << "," << k << "," << l << "]" << std::endl;
                            mistake = true;
                            break;
                        }
                    }
                }
                if(mistake)
                {
                    break;
                }
            }
            if(mistake)
            {
                break;
            }
        }
        if(mistake)
        {
            break;
        }
    }
    if(mistake){
        std::cout << "fixing" << std::endl;
        fixMistakes();
    }
}

void board::fixMistakes()
{

    int wrongNumber = guesses.getToLastGuess()->numberGuessed;



    int I = guesses.getToLastGuess()->coordinates[0];
    int J = guesses.getToLastGuess()->coordinates[1];
    int K = guesses.getToLastGuess()->coordinates[2];
    int L = guesses.getToLastGuess()->coordinates[3];

    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int k=0; k<3; k+=1)
            {
                for(int l=0; l<3; l+=1)
                {
                    mainBoard[i][j][k][l] = guesses.getToLastGuess()->mainBoard[i][j][k][l];
                    for(int m=0; m<10; m+=1)
                    {
                        possibilityBoard[i][j][k][l][m] = guesses.getToLastGuess()->possibilityBoard[i][j][k][l][m];
                    }
                }
            }
        }
    }

    possibilityBoard[I][J][K][L][wrongNumber] = 0;

    guesses.displayAll(guesses.getHead());
    guesses.deleteAfter(guesses.getToLastGuess());
    guesses.displayAll(guesses.getHead());
}

void board::printMainBoard()
{
    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            std::cout << std::endl;
            for(int k=0; k<3; k+=1)
            {
                for(int l=0; l<3; l+=1)
                {
                    std::cout << mainBoard[i][k][j][l];
                }
            }
        }
    }
    std::cout << std::endl;
}

void board::start(int inputBoard[3][3][3][3])
{
    fillMainBoard(inputBoard);
    fillPossibilityBoard();
    possibilityBoardPass();
}

void board::go()
{
    while(!checkIfFilled()){
        makeChoice();
        fillPossibilityBoard();
        possibilityBoardPass();
        findAndFixMistakes();
    }
}

void board::end()
{
    std::cout << "The end" << std::endl;
    printMainBoard();
}



