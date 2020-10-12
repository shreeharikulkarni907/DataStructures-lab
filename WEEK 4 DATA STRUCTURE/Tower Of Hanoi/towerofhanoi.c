#include<stdio.h>
void move(int n,char a,char b,char c);
int main()
{
    int n;
    printf("Enter the number of discs to be moved\n");
    scanf("%d",&n);
    printf("A:Source\nB:Spare\nC:Destination\n");
    move(n,'A','C','B');

    return 0;
}
void move(int n,char source,char destination,char spare)
{
    if(n==1)
        printf("Move  from %c to %c\n",source,destination);
    else
    {
        move(n-1,source,spare,destination);
        move(1,source,destination,spare);
        move(n-1,spare,destination,source);
    }
}
