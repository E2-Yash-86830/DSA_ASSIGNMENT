#include<stdio.h>
int size=5;
int linear(int arr[],int size, int key)
{
    if(size ==0)
    {
        return -1;
    }
    if(arr[size -1]==key)
    {
        return size -1;
    }
    linear (arr,size-1,key);
}
int main()
{
    int key;
    int arr[]={1,2,3,4,5};
    printf("Enter the key : ");
    scanf("%d",&key);
    int result=linear(arr,size,key);
    if(result==-1)
    printf("Element not found");
    else
    printf("element found at index %d\n",result);
    return 0;
}