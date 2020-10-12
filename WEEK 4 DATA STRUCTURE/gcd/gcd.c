#include<stdio.h>
int gcd(int x,int y);
int main()
{
    int x,y;
    printf("Enter two numbers\n");
    scanf("%d %d",&x,&y);
    int answer=gcd(x,y);
    printf("GCD of %d and %d is %d\n",x,y,answer);
}
int gcd(int x,int y)
{
    int rem=x%y;
    if(rem==0)
        return y;
    else
        return gcd(y,rem);
}
