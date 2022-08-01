#include <stdlib.h>
#include <string.h>
#include "Queue.h"

//Initializes the queue.
void QueueCreate(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}


//Push new element to the end of the stack, assuming the stack is not full.
int QueueAppend( Queue *pq, void* value, int size)
{
    QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
    if (pn == NULL)
        return 0;
    //Entry lines.
    void *ptr = malloc(size);
    memcpy(ptr, value, size);
    pn->entry = ptr;
    //End of entry lines.
    if (pq->size == 0)
        pq->front = pn;
    else
        pq->rear->next = pn;

    pq->rear = pn;
    pn->next = NULL;
    pq->size++;
    return 1;


}

//Pops the last element
void QueueServe(Queue *pq, void **element, int size)
{
    //Moving the data and freeing the pointer
    memcpy(*element, pq->front->entry, size);
    free(pq->front->entry);

    QueueNode *temp= pq->front;
    pq->front = pq->front->next;
    free(temp);
    pq->size--;
    if(pq->size == 0)
        pq->rear = NULL;


}

//Checks if queue empty
int QueueEmpty(Queue *pq)
{
    return (pq->size == 0);
}

//Checks if queue full
int QueueFull(Queue *pq)
{
    return 0;
}

//Returns Queue size
int Queuesize(Queue *pq)
{
    return pq->size;
}
//Clears the queue
void ClearQueue(Queue *pq)
{
    QueueNode *temp;
    while (pq->front != NULL)
    {
        temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
    }
    pq->size = 0;
}

//Traverse over Queue elements
void TraverseQueue(Queue *pq, void(*pfun)(void*))
{
    QueueNode *tmp;
    for (tmp = pq->front; tmp != NULL; tmp = tmp->next)
       (*pfun)(tmp->entry);

}
