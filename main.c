#include<stdio.h>
#include"BST.h"

int main()
{
    int choice,data;
    struct node* key;
    while(menu(&choice)!=0)
    {
        switch(choice)
        {
            case 1:printf("Enter the data you want: ");
                   scanf("%d",&data);
                   add_node(data);
                  break;
            case 2:printf("Enter the data you want: ");
                   scanf("%d",&data);
                  struct node *parent_node = create_node();
                  parent_node->data=data;
                   add_node_by_recursion(data,root,parent_node);
                  break;
            case 3:recursive_pre_order(root);
                  break;
            case 4:recursive_in_order(root);
                  break;
            case 5:recursive_post_order(root);
                  break;
            case 6:non_recursive_pre_order();
                  break;
            case 7:non_recursive_in_order();
                  break;
            case 8:BFS_traversal();
                  break;
            case 9:DFS_traversal();
                  break;
            case 10:printf("Enter the key you want to find: ");
                   scanf("%d",&data);
                   key=BFS_search_element(data);
                   key==NULL?printf("Key is not found!!\n"):printf("key %d is found!!\n",key->data);
                  break;
            case 11:printf("Enter the key you want to find: ");
                   scanf("%d",&data);
                   key=DFS_search_element(data);
                   key==NULL?printf("Key is not found!!\n"):printf("key %d is found!!\n",key->data);
                  break;
            case 12:printf("Enter the key you want to find: ");
                   scanf("%d",&data);
                   key=BST_search_element(data);
                   key==NULL?printf("Key is not found!!\n"):printf("key %d is found!!\n",key->data);
                  break;    
            case 13:printf("Enter the key you want to find: ");
                   scanf("%d",&data);
                   struct node *parent;
                   key=BST_search_parent(data,&parent);
                   key==NULL?printf("Key is not found!!\n"):printf("key %d is found!! with parent %d key\n",key->data,parent->data);
                  break;    
            case 14:printf("Enter the key you want to delete: ");
                   scanf("%d",&data);
                   int key=Delete_node(data);
                   key==-1?printf("Key is not found!!\n"):printf("Key deleted successfully!!\n");
                  break;           
            default:printf("Enter valid choice!!\n");
        }
    }
    return 0;
}