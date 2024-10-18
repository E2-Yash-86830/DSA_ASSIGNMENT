#include<stdio.h>
#define SIZE 5
int left=0,right=SIZE-1,mid,result,key;
int sort(int arr[SIZE],int key,int mid,int left,int right)
{
    if(left>right)
    return -1;
        mid=(left+right)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(key<arr[mid])
        {
            result=sort(arr,key,mid,left,mid-1);

        }
        else{
            result=sort(arr,key,mid,mid+1,right);

        }
        return result;

}
int main()
{
    int mid;
    int arr[SIZE]={1,2,3,4,5};
    printf("Enter the key you want to search :\n");
    scanf("%d",&key);

    result=sort(arr,key,mid,left,right);
    if(result==-1)
    {
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n",result);
    }
    return 0;
}