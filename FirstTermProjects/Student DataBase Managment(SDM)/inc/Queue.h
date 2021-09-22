#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
/*
* This was implemented by Eng: Ziad Ashraf in 2020.
*/


typedef struct queuenode
{
    void *entry;
    struct queuenode* next;

}QueueNode;

typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
    int size;
}Queue;


//Initializes the Queue.
void QueueCreate(Queue *);

//Append new element to the end of the queue, assuming the queue is not full.
//Pre:Queue is not full.
int QueueAppend(Queue *, void*, int);

//Serve the front (first in) element and remove it from the queue.
//Pre:Queue is not empty.
void QueueServe	(Queue *, void **, int);

//Checks if queue empty
int QueueEmpty(Queue *);

//Checks if queue full
int QueueFull(Queue *);

//Returns Queue size
int Queuesize(Queue *);

//Clears the queue
//Pre:The Queue is not empty.
void ClearQueue(Queue *);

//Traverse over Queue elements
void TraverseQueue(Queue *, void(*pfun)(void*));
#endif // QUEUE_H_INCLUDED
