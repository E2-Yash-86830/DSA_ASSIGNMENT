#include"BST.h"
#include"stack.h"
#include"linear_queue.h"
#include<stdio.h>
#include<stdlib.h>

node *root=NULL;
node* create_node()
{
   node *parent_node=(node*)malloc(sizeof(node));
   parent_node->left=NULL;
   parent_node->right=NULL;
   parent_node->data=0;
   return parent_node;
}

void add_node(int data)
{
   node *parent_node=create_node();
   parent_node->data=data;
   
   if(root==NULL)
   {
      root=parent_node;
   }
   else
   {
      node *trav=root;
      while(1)
      {
        if(data < trav->data)
        {
            if(trav->left==NULL)
            {
                trav->left=parent_node;
                break;
            }
            else
                trav=trav->left;
        }
        else
        {
            if(trav->right==NULL)
            {
                trav->right=parent_node;
                break;
            }
            trav=trav->right;
        }
      }
   }
}

int menu(int *ch)
{
   printf("\n0.Exit\n1.Add a node in Binary Search tree\n2.Add a node in BST by recursive manner\n3.Display BST by recursive pre-order\n");
   printf("4.Display BST by recursive in-order\n5.Display BST by recursive post-order\n");
   printf("6.Display BST by non_recursive pre-order\n7.Display BST by non_recursive in-order\n");
   printf("8.BFS traversal\n9.DFS traversal\n10.Search a key by BFS\n");
   printf("11.Search a key by DFS\n12.Search a key by BST\n13.Search a key by BST with parent\n14.Delete node\n");
   printf("Enter the choice: ");
   scanf("%d",ch);
   return *ch;
}

void recursive_pre_order(struct node* trav)
{
    if(trav==NULL)
        return;
    
    printf("%d\t",trav->data);
    recursive_pre_order(trav->left);
    recursive_pre_order(trav->right);
}

void recursive_in_order(struct node* trav)
{
    if(trav==NULL)
        return;
    
    recursive_pre_order(trav->left);
    printf("%d\t",trav->data);
    recursive_pre_order(trav->right);
}

void recursive_post_order(struct node* trav)
{
    if(trav==NULL)
        return;
    
    recursive_pre_order(trav->left);
    recursive_pre_order(trav->right);
    printf("%d\t",trav->data);
}

void non_recursive_pre_order()
{
    STACK ST;
    stack_init(&ST);
    node *trav=root;
    printf("Pre-order: ");
    while(trav!=NULL || !is_stack_empty(&ST))
    {
        while(trav!=NULL)
        {
            printf("%d\t",trav->data);
            if(trav->right!=NULL)
                push(&ST,trav->right);
            trav=trav->left;
        }
        if(!is_stack_empty(&ST))
        {
            trav=peek_stack(&ST);
            pop(&ST);
        }   
    }
    printf("\n");
}

void non_recursive_in_order()
{
   STACK ST;
   stack_init(&ST);
   node *trav=root;
   printf("In-order: ");
   while(trav!=NULL || !is_stack_empty(&ST))
   {
        while(trav!=NULL)
        {
            push(&ST,trav);
            trav=trav->left;
        }
        if(!is_stack_empty(&ST))
        {
            trav=peek_stack(&ST);
            pop(&ST);
        }
        printf("%d\t",trav->data);
        trav=trav->right;
   }
   printf("\n");
}

void BFS_traversal()
{
    S_QUE Q;
    queue_init(&Q);
    node *trav=root;
    if(trav==NULL)
       return;
    enqueue(&Q,trav);
    printf("BFS traversal: ");
    while(!is_queue_empty(&Q))
    {
        trav=peek(&Q);
        dequeue(&Q);
        printf("%d\t",trav->data);
        if(trav->left!=NULL)
        {
            enqueue(&Q,trav->left);
        }
        if(trav->right!=NULL)
        {
            enqueue(&Q,trav->right);
        }
    }
    printf("\n");
}

void DFS_traversal()
{
   STACK ST;
   stack_init(&ST);
    
   node *trav=root;
   if(trav==NULL)
       return;
   push(&ST,trav);
   printf("DFS traversal: ");
   while(!is_stack_empty(&ST))
   {
        trav=peek_stack(&ST);
        pop(&ST);
        printf("%d\t",trav->data);
        if(trav->right!=NULL)
        {
            push(&ST,trav->right);
        }
        if(trav->left!=NULL)
        {
            push(&ST,trav->left);
        }
   }
   printf("\n");
}

struct node* BFS_search_element(int key)
{
    S_QUE Q;
    queue_init(&Q);
    node *trav=root;
    if(trav==NULL)
       return NULL;
    enqueue(&Q,trav);
    while(!is_queue_empty(&Q))
    {
        trav=peek(&Q);
        dequeue(&Q);
        if(trav->data==key)
            return trav;
        if(trav->left!=NULL)
        {
            enqueue(&Q,trav->left);
        }
        if(trav->right!=NULL)
        {
            enqueue(&Q,trav->right);
        }
    }
    return NULL;
}

 struct node* DFS_search_element(int key)
 {
    STACK ST;
    stack_init(&ST);

    node *trav=root;
    if(trav==NULL)
       return NULL;
    push(&ST,trav);
    while(!is_stack_empty(&ST))
    {
       trav=peek_stack(&ST);
       pop(&ST);
       if(trav->data==key)
          return trav;
       if(trav->right!=NULL)
       {
         push(&ST,trav->right);
       }
       if(trav->left!=NULL)
       {
         push(&ST,trav->left);
       }
    }
    return NULL;
 }

 struct node* BST_search_element(int key)
 {
    node *trav=root;

    while(trav!=NULL)
    {
        if(trav->data==key)
            return trav;
        if(key > trav->data)
            trav=trav->right;
        else 
            trav=trav->left;
    }
    return NULL;
 }

 void add_node_by_recursion(int data,struct node* trav,struct node *parent_node)
 {
    if(root==NULL)
    {
        root=parent_node;
    }
    else
    {
        if(data < trav->data)
        {
            if(trav->left==NULL)
            {
                trav->left=parent_node;
            }
            else
                add_node_by_recursion(data,trav->left,parent_node);
        }
        else
        {
            if(trav->right==NULL)
            {
                trav->right=parent_node;
            }
            else
                add_node_by_recursion(data,trav->right,parent_node);
        }
    }
 }

 struct node* BST_search_parent(int key,struct node **parent)
 {
    node *trav=root;
    
    *parent=NULL;
    while(trav!=NULL)
    {
        if(trav->data == key)
          return trav;
        
        *parent=trav;
        if(key < trav->data)
            trav=trav->left;
        else 
           trav=trav->right;
    }
    *parent=NULL;
    return NULL;
 }

int Delete_node(int data)
{
    printf(".....\n");
    struct node *parent=NULL;
    struct node *temp=BST_search_parent(data,&parent);
    struct node *succ=NULL;
    if(temp==NULL)
       return -1;

    else
    {
        if(temp->left!=NULL && temp->right!=NULL);
        {
            succ=temp->right;
            parent=temp;
            while(succ->left!=NULL)
            {
                parent=succ;
                succ=succ->left;
            }
            temp->data=succ->data;
            temp=succ;
        }

        if(temp->left==NULL)
        {
            if(temp==root)
                root=temp->right;
            else if(temp==parent->left)
                parent->left=temp->right;
            else
                parent->right=temp->right;
        }

        if(temp->right==NULL)
        {
            if(temp==root)
                root=temp->left;
            else if(temp==parent->left)
                parent->left=temp->left;
            else
                parent->right=temp->left;
        }
        free(temp);
        temp=NULL;
    }
    return 1;
}