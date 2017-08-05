//
// Created by ju5t1nas on 2017-08-04.
//

#ifndef SUDOKU_SOLVER_BOARD_H
#define SUDOKU_SOLVER_BOARD_H
#include "board.h"
#include "GLogLinkedList.h"

class board {


private:
    //Declaring all the different boards
    //Main board is the board which will be constantly updated.
    int mainBoard[3][3][3][3] = {{{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}},
                                 {{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}},
                                 {{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}}};

    //Possibility board is for tracking possible numbers that can be put in each Sudoku board tile.
    int possibilityBoard[3][3][3][3][10];

    //We initialise a Linked List of guesses made.
    GLogLinkedList guesses;

    //
    void fillMainBoard(int inputBoard[3][3][3][3]);
    void fillPossibilityBoard();

    //Functions for the main loop
    bool checkIfFilled();

    void makeChoice();
        //This function goes into the makeChoice() function.
        void guess(int coordinates[4], int priority);


    void possibilityBoardPass();
        //This function goes into the possibilityBoardPass()
        void findPossibilities(int coordinates[4]);

    void findAndFixMistakes();
        //This function goes into the findAndFixMistakes() function.
        void fixMistakes();

    //Functions for constructor to run;
    void start(int inputBoard[3][3][3][3]);
    void go();
    void end();


public:
    board(int inputBoard[3][3][3][3])
    {
        start(inputBoard);
        go();
        end();
    }

};


#endif //SUDOKU_SOLVER_BOARD_H
