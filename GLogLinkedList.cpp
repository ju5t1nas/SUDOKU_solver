//
// Created by ju5t1nas on 2017-08-04.
//

#include "GLogLinkedList.h"

void GLogLinkedList::add_node(int coor[4], int num, int guessP, int possBoard[3][3][3][3][10])
{
    node *tmp = new node;
    for(int i=0; i<4; i+=1)
    {
        tmp->coordinates[i] = coor[i];
    }
    tmp->numberGuessed = num;
    tmp->guessPriority = guessP;

    for(int i=0; i<3; i+=1)
    {
        for(int j=0; j<3; j+=1)
        {
            for(int k=0; k<3; k+=1)
            {
                for(int l=0; l<3; l+=1)
                {
                    for(int m=0; m<10; m+=1)
                    {
                        tmp->possibilityBoard[i][j][k][l][m] = possBoard[i][j][k][l][m];
                    }
                }
            }
        }
    }

    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

node* GLogLinkedList::getHead()
{
    return head;
}

node* GLogLinkedList::getTail()
{
    return tail;
}

node* GLogLinkedList::getToLastGuess()
{
    node *tmp;
    tmp = head;

    node *wanted;

    while(tmp->next != NULL)
    {
        if(tmp->guessPriority != 1)
        {
            wanted = tmp;
        }
        tmp = tmp->next;

    }
    return wanted;
}

void GLogLinkedList::displayAll(node *head)
{
    if(head==NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        std::cout << head->coordinates[0] << head->coordinates[1] << head->coordinates[2] << head->coordinates[3] << "," << head->numberGuessed << ", " << head->guessPriority << std::endl;
        displayAll(head->next);
    }
}

void GLogLinkedList::deleteAfter(node *after)
{
    if(after->next != NULL)
    {
        delete after->next;
    }

    after->next = NULL;
    tail = after;
}
