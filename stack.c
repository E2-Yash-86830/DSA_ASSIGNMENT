#include"stack.h"
#include<stdio.h>

void stack_init(STACK *st)
{
    st->top=-1;
}

int is_stack_full(STACK *st)
{
    return (st->top == SIZE-1);
}

int is_stack_empty(STACK *st)
{
    return (st->top == -1);
}

void push(STACK *st,struct node* data)
{
    st->top++;
    st->arr[st->top]=data;
}

void pop(STACK *st)
{
    st->arr[st->top]=0;
    st->top--;
}

struct node* peek_stack(STACK *st)
{
    return st->arr[st->top];
}
