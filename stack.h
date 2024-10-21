#ifndef __STACK_H
#define __STACK_H

#include"BST.h"
#define SIZE 10

typedef struct stack
{
    struct node* arr[SIZE];
    int top;
}STACK;   

void stack_init(STACK*);
int is_stack_full(STACK *st);
int is_stack_empty(STACK *st);
void push(STACK *st,struct node*);
void pop(STACK *st);
struct node* peek_stack(STACK *);

#endif
