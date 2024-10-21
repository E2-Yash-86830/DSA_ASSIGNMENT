#include<stdio.h>
#include"linear_queue.h"

void queue_init(S_QUE *q)
{
   q->rear=-1;
   q->front=-1;
}

void enqueue(S_QUE *q,node* data)
{
   q->rear++;
   q->arr[q->rear]=data;
   if(q->front == -1)
       q->front=0;
}

int is_queue_full(S_QUE *q)
{
    return (q->rear == SIZE1-1);
}

int is_queue_empty(S_QUE *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void dequeue(S_QUE *q)
{
    q->arr[q->front]=0;
    q->front++;
}

struct node* peek(S_QUE *q)
{
    return q->arr[q->front];
}
