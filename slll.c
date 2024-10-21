#include<stdio.h>
#include<stdlib.h>


struct node *head= NULL;
struct node
{
    int data;
    struct node *next;
};

int menu_slll(int*);
struct node* create_node();
void add_at_first_pos(int);
void add_at_last_pos(int);
void add_at_specific_pos(int,int*);
int enter_data(int*);
int enter_pos(int*);
int count_nodes();
void delete_from_first_pos();
void delete_from_last_pos();
void delete_from_specific_pos(int);
void display_slll();
void slll_linear_search();
void slll_find_mid();
void reverse_slll();
void selection_sort();

int main()
{
    int choice,data,pos;
    while(menu_slll(&choice)!=0)
    {
       switch(choice)
       {
          case 1:add_at_first_pos(enter_data(&data));
                 display_slll();
                 break;
          case 2:add_at_last_pos(enter_data(&data));
                 display_slll();
                 break;
          case 3:add_at_specific_pos(enter_pos(&pos),&data);
                 display_slll();
                 break;
          case 4:delete_from_first_pos();
                 display_slll();
                 break;
          case 5:delete_from_last_pos();
                 display_slll();
                 break;
          case 6:delete_from_specific_pos(enter_pos(&pos));
                 display_slll();
                 break;
          case 7:slll_linear_search();
                 break;
          case 8:slll_find_mid();
                 break;
          case 9:reverse_slll();
                 display_slll();
                 break;
          case 10:selection_sort();
                 display_slll();
                 break;
          default:printf("Enter valid choice!!\n");
       }
    }
    return 0;
}

int menu_slll(int *ch)
{
    printf("\n0.Exit\n1.Add node at first position\n2.Add node at last position\n3.Add node at specitic position\n");
    printf("4.Delete node from first position\n5.Delete node from last position\n6.Delete node from specitic position\n");
    printf("7.Search element\n8.Find mid element\n9.Reverse SLLL\n10.Sort SLLL\n");
    printf("Enter the choice: ");
    scanf("%d",ch);
    return *ch;
}

struct node* create_node()
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));

    ptr->data=0;
    ptr->next=NULL;
    return ptr;
}

int enter_data(int *data)
{
   printf("Enter data you want to add or search: ");
   scanf("%d",data);
   return *data;
}

int enter_pos(int *pos)
{
   printf("Enter node position you want: ");
   scanf("%d",pos);
   return *pos;
}

void add_at_first_pos(int data)
{
    struct node* ptr=create_node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
       ptr->next=head;
       head=ptr;
    }
}

void add_at_last_pos(int data)
{
     struct node* ptr=create_node();
     ptr->data=data;
     if(head==NULL)
     {
        head=ptr;
     }
     else
     {
        struct node* trav=head;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next=ptr;
     }
}

void add_at_specific_pos(int pos,int *data)
{
   if(head==NULL)
   {
      if(pos==1)
         add_at_first_pos(enter_data(data));
      else 
         printf("Invalid Positon!!\n");
   }
   else if(pos==1)
     add_at_first_pos(enter_data(data));
   else if(pos==count_nodes()+1)
     add_at_last_pos(enter_data(data));
   else if(pos<1 || pos>count_nodes()+1)
     printf("Invalid Position!!\n");
   else 
   {
      struct node* ptr=create_node();
      ptr->data=enter_data(data);
      struct node* trav=head;
      int i=1;
      while(i<pos-1)
      {
         trav=trav->next;
         i++;
      }
      ptr->next=trav->next;
      trav->next=ptr;
   }
}

int count_nodes()
{
    int count=0;
    struct node* trav=head;
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
       printf("SCLL is empty!!\n");
    else if(head->next==NULL)
    {
         free(head);
         head=NULL;
    }
    else 
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}

void delete_from_last_pos()
{
   if(head==NULL)
       printf("SCLL is empty!!\n");
   else if(head->next==NULL)
   {
        free(head);
        head=NULL;
   }
   else
   {
       struct node *trav=head;
       while(trav->next->next!=NULL)
       {
          trav=trav->next;
       }
       struct node *temp=trav->next;
       trav->next=NULL;
       free(temp);
       temp=NULL;
   }
}

void delete_from_specific_pos(int pos)
{
    if(head==NULL)
    {
        if(pos==1)
          printf("SCLL is empty!!\n");
    }
    else if(pos==1)
       delete_from_first_pos();
    else if(pos==count_nodes())
      delete_from_last_pos();
    else if(pos<1 || pos>count_nodes())
      printf("Invalid Position!!\n");
    else
    {
        struct node *trav=head;
        int i=1;
        while(i<pos-1)
        {
            trav=trav->next;
            i++;
        }
        struct node *temp=trav->next;
        trav->next=trav->next->next;
        free(temp);
        temp=NULL;
    }
}

void display_slll()
{
   struct node *trav=head;
   while(trav!=NULL)
   {
      printf("%d\t",trav->data);
      trav=trav->next;
   }
   printf("\n");
}

void slll_linear_search()
{
   if(head==NULL)
      printf("SLLL is empty!!\n");
   else
   {
      int count=0,flag=0,data=enter_data(&data);
      struct node *trav=head;
      while(trav!=NULL)
      {
         count++;
         if(trav->data==data)
         { 
            flag=1;
            break;
         }
         trav=trav->next;
      }

      if(flag==1)
         printf("%d element at node = %d\n",data,count);
      else
         printf("Element not found!!\n"); 
   }
}

void slll_find_mid()
{
   if(head==NULL)
      printf("SLLL is empty!!\n");
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

void reverse_slll()
{
   if(head==NULL)
      printf("SLLL is empty!!\n");
   else if(head->next==NULL)
      head=head;
   else
   {
      struct node *n1=head;
      struct node *n2=head->next;

      while(n2!=NULL)
      {
         struct node *n3=n2->next;
         n2->next=n1;
         n1=n2;
         n2=n3;
      }
      head->next=NULL;
      head=n1;
   }
}

void selection_sort()
{
    if(head==NULL)
       printf("SLLL is empty!!\n");
    else
    {
        struct node *sel_pos=NULL;
        struct node *pos=NULL;
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