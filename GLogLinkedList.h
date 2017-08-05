//
// Created by ju5t1nas on 2017-08-04.
//

#ifndef SUDOKU_SOLVER_GLOGLINKEDLIST_H
#define SUDOKU_SOLVER_GLOGLINKEDLIST_H

#include <iostream>

struct node
{
    int coordinates[4];
    int numberGuessed;
    int guessPriority;
    int possibilityBoard[3][3][3][3][10];
    struct node *next;
};

class GLogLinkedList
{
private:
    node *head, *tail;
public:
    GLogLinkedList(){
        head = NULL;
        tail = NULL;
    }

    //Declaring function for adding a node.
    void add_node(int coor[4], int num, int guessP, int possBoard[3][3][3][3][10]);

    //Declaring function for getting the first node.
    node* getHead();

    //Declaring function for getting the last node.
    node* getTail();

    //Function for printing all information of all nodes.
    void displayAll(node *head);

    node* getToLastGuess();

    void deleteAfter(node* after);
};

#endif //SUDOKU_SOLVER_GLOGLINKEDLIST_H
