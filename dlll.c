#include<stdio.h>
#include<stdlib.h>

struct node *head= NULL;
struct node *tail= NULL;
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

int menu_dlll(int*);
node* create_node();
int enter_data(int*);
int enter_pos(int*);
void add_at_first_pos(int);
void add_at_last_pos(int);
void display_dlll();
void add_at_specific_pos(int,int*);
int count_nodes();
void delete_from_first_pos();
void delete_from_last_pos();
void delete_from_specific_pos(int);
void selection_sort();
void dlll_linear_search();
void dlll_find_mid();

int main()
{
    int choice,data,pos;
    while(menu_dlll(&choice)!=0)
    {
       switch(choice)
       {
          case 1:add_at_first_pos(enter_data(&data));
                 display_dlll();
                 break;
          case 2:add_at_last_pos(enter_data(&data));
                 display_dlll();
                 break;
          case 3:add_at_specific_pos(enter_pos(&pos),&data);
                 display_dlll();
                 break;
          case 4:delete_from_first_pos();
                 display_dlll();
                 break;
          case 5:delete_from_last_pos();
                 display_dlll();
                 break;
          case 6:delete_from_specific_pos(enter_pos(&pos));
                 display_dlll();
                 break;
          case 7:selection_sort();
                 display_dlll();
                 break;
          case 8:dlll_linear_search();
                 break;
          case 9:dlll_find_mid();
                 break;
          default:printf("Enter valid choice!!\n");
       }
    }
    return 0;
}

int menu_dlll(int *ch)
{
    printf("\n0.Exit\n1.Add node at first position\n2.Add node at last position\n3.Add node at specitic position\n");
    printf("4.Delete node from first position\n5.Delete node from last position\n6.Delete node from specific position\n");
    printf("7.Sort DCLL\n8.Search element\n9.Find middle element\n");
    printf("Enter the choice: ");
    scanf("%d",ch);
    return *ch;
}

node* create_node()
{
    node *new_node=(node*)malloc(sizeof(node));
    if(new_node==NULL)
       printf("malloc is failed!!\n");
    
    new_node->prev=NULL;
    new_node->data=0;
    new_node->next=NULL;
    return new_node;
}

int enter_data(int *data)
{
    printf("Enter the data you want: ");
    scanf("%d",data);
    return *data;
}

int enter_pos(int *pos)
{
    printf("Enter the position you want: ");
    scanf("%d",pos);
    return *pos;
}

void add_at_first_pos(int data)
{
     node *new_node=create_node();
     new_node->data=data;

     if(head==NULL)
     {
        head=new_node;
        tail=head;
     }
     else 
     {
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
     }
}

void add_at_last_pos(int data)
{
    node *new_node=create_node();
    new_node->data=data;

    if(head==NULL)
    {
        head=new_node;
        tail=new_node;
    }
    else
    {
       tail->next=new_node;
       new_node->prev=tail;
       tail=new_node;
    }
}

void display_dlll()
{
    if(head==NULL)
      printf("DLLL is empty!!\n");
    else
    {
        node *trav=head;
        while(trav!=NULL)
        {
            printf("%d\t",trav->data);
            trav=trav->next;
        }
        printf("\n");
    }
}

void add_at_specific_pos(int pos,int *data)
{
   if(head==NULL)
   {
      if(pos==1)
         add_at_first_pos(enter_data(data));
      else 
         printf("DLLL is empty!!\n");
   }
   else if(pos==1)
      add_at_first_pos(enter_data(data));
    
   else if(pos==count_nodes()+1)
      add_at_last_pos(enter_data(data));
   
   else if(pos<1 || pos>count_nodes()+1)
       printf("Invalid Position!!\n");

   else
   {
       node *new_node=create_node();
       new_node->data=enter_data(data);

       node*trav=head;
       int i=1;
       while(i<pos-1)
       {
          i++;
          trav=trav->next;
       }
       new_node->prev=trav;
       new_node->next=trav->next;
       trav->next->prev=new_node;
       trav->next=new_node;
   }   
}

int count_nodes()
{
    int count=0;
    node *trav=head;
    while(trav!=NULL)
    {
       count++;
       trav=trav->next;
    }
    return count;
}

void delete_from_first_pos()
{
    if(head==NULL)
       printf("DLLL is empty!!\n");
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        temp=NULL;
    }
}

void delete_from_last_pos()
{
    if(head==NULL)
       printf("DLLL is empty!!\n");
    else if(head==tail)
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
       tail=tail->prev;
       free(tail->next);
       tail->next=NULL;
    }
}

void delete_from_specific_pos(int pos)
{
   if(head==NULL)
   {
      if(pos==1)
         printf("DLLL is empty!!\n");
   }
   else if(pos==1)
      delete_from_first_pos();
    
   else if(pos==count_nodes())
      delete_from_last_pos();
   
   else if(pos<1 || pos>count_nodes())
       printf("Invalid Position!!\n");

   else
   {
       node*trav=head;
       int i=1;
       while(i<pos)
       {
          i++;
          trav=trav->next;
       }
       trav->prev->next=trav->next;
       trav->next->prev=trav->prev;
       free(trav);
       trav=NULL;
   }   
}

void selection_sort()
{
    if(head==NULL)
       printf("DLLL is empty!!\n");
    else
    {
        node *sel_pos=NULL;
        node *pos=NULL;
        for(sel_pos=head;sel_pos->next!=NULL;sel_pos=sel_pos->next)
        {
            for(pos=sel_pos->next;pos!=NULL;pos=pos->next)
            {
                if(sel_pos->data > pos->data)
                {
                    int temp=sel_pos->data;
                    sel_pos->data=pos->data;
                    pos->data=temp;
                }
            }
        }
    }
}

void dlll_linear_search()
{
   if(head==NULL)
      printf("DLLL is empty!!\n");
   else
   {
      int count=0,flag=0,data=enter_data(&data);
      struct node *trav=head;
      do
      {
         count++;
         if(trav->data==data)
         { 
            flag=1;
            break;
         }
         trav=trav->next;
      }while(trav!=NULL);

      if(flag==1)
         printf("%d element at node = %d\n",data,count);
      else
         printf("Element not found!!\n"); 
   }
}

void dlll_find_mid()
{
   if(head==NULL)
      printf("DLLL is empty!!\n");
   else
   {
        struct node* slow=head;
        struct node* fast=head;

        while(fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==NULL)
                break;
        }
        printf("Mid position element = %d\n",slow->data);
   }
}