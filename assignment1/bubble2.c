#include<stdio.h>
#define SIZE 5
int cmp=0;pass=0;
int bubble(int arr[SIZE])
{
    int temp;
    for(int i=0;i<SIZE-1-i;i++)
    {
        for(int j=i+1;j<SIZE-i;j++)
        {
            if(arr[i]>arr[j])
            {
                cmp++;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        pass ++;
    }
}
int main()
{
    int arr[SIZE]={5,4,3,2,1};
    bubble(arr);
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("Number of comparisons %d\n",cmp);
    printf("Number of passes : %d\n",pass);
    return 0;
}