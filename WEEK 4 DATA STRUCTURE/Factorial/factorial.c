#include<stdio.h>
long int fact(int n);
int main()
{
    int n;
    int val;
    printf("Enter the number whose factorial is to be found\n");
    scanf("%d",&n);
    val=fact(n);
    printf("Factorial of the number is %d\n",val);
    return 0;
}
long int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return(n*fact(n-1));
    }
}
