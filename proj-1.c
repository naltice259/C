#include <stdio.h>
#include <stdlib.h>
#include "q.h"


int main()
{
    Queue *q;
    InitQueue(&q);
    printf("Empty queue is %d\n", q);
    Queue *item1;
    item1 = NewItem(1);
    AddQueue(&q, item1);
    Queue *item2;
    item2 = NewItem(2);
    AddQueue(&q, item2);
    Queue *item3;
    item3 = NewItem(3);
    AddQueue(&q, item3);
    RotateQ(&q);
    printf("queue head is %d\n", q->payload);
    /*Queue *deleted1;
    deleted1 = DelQueue(&q);
    Queue *deleted2;
    deleted2 = DelQueue(&q);
    Queue *deleted3;
    deleted3 = DelQueue(&q);
    printf("Item3 is %d\n", deleted1->payload);
    printf("Item2 is %d\n", deleted2->payload);
    printf("Item1 is %d\n", deleted3->payload);
    printf("Empty queue is %d\n", q);*/
    
    return 0;
}
