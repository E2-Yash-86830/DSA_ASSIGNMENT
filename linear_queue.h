#ifndef __LINEAR_QUEUE_H
#define __LINEAR_QUEUE_H

#include"BST.h"
#include"stack.h"

#define SIZE1 15
typedef struct queue
{
   node* arr[SIZE1];
   int rear;
   int front;
}S_QUE;

int queue_menu(int*);
void queue_init(S_QUE*);
void enqueue(S_QUE*,node*);
int is_queue_full(S_QUE*);
int is_queue_empty(S_QUE*);
void dequeue(S_QUE*);
struct node* peek(S_QUE*);

#endif