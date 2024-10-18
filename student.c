#include<stdio.h>
#include<string.h>
struct student{
    int roll_no;
    char name[20];
    float marks;
};
int main(){
    struct student s[6],temp;

    strcpy(s[0].name, "Yash");
    s[0].marks=10;
    s[0].roll_no=1;
    strcpy(s[1].name,"Suraj");
    s[1].marks =20;
    s[1].roll_no=2;
    strcpy(s[2].name, "Roshan");
    s[2].marks =30;
    s[2].roll_no =3;
    strcpy(s[3].name,"Guru");
    s[3].marks =40;
    s[3].roll_no=4;
    strcpy(s[3].name,"Satyam");
    s[4].marks = 50;
    s[4].roll_no =5;


for (int i=0;i<5;i++){
    for(int j=i+1;j<6;j++)
    {
        if(s[i].marks>s[j].marks)
        {
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
    }
}

printf("Roll_no\t\tName\t\tMarks\n");
for(int i=0;i<10;i++)
{
    printf("%4d",s[i].roll_no);
    printf("\t\t%s",s[i].name);
    printf("\t\t%f\n",s[i].marks);
}
return 0;
}