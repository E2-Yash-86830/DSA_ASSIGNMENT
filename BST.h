
#ifndef __BST_H
#define __BST_H

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}node;

extern node *root;
node* create_node();
void add_node(int);
void recursive_pre_order(struct node*);
void recursive_in_order(struct node*);
void recursive_post_order(struct node*);
void non_recursive_pre_order();
void non_recursive_in_order();
void BFS_traversal();
int menu(int*);
void DFS_traversal();
struct node* BFS_search_element(int);
struct node* DFS_search_element(int);
struct node* BST_search_element(int key);
void add_node_by_recursion(int,struct node*,struct node *);
struct node* BST_search_parent(int data,struct node**);
int Delete_node(int data);
#endif