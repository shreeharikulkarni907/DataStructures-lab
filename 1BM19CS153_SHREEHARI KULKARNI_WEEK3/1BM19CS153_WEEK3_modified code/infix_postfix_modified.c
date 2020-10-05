#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[100];
int top1=-1;
/*code to check validity of Expression*/
int check(char a[])
{
    for (int i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	}
	return(find_top());

}
void push(char a)
{
	stack[++top1] = a;
}
void pop()
{
	if (top1 == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}
	else
	{
		top1--;
	}
}
int find_top()
{
	if (top1 == -1)
		return 1;
	else
        return 0;
}

/*END OF CHECK FOR INVALID EXPRESSION*/
int F(char symbol)
{
    switch(symbol)
    {

    case '+':
    case '-':
        return 2;


    case '*':
    case '/':
        return 4;


    case '^':
    case '$':
        return 5;

    case '(':
        return 0;


    case '#':
        return -1;


    default:
        return 8;

    }
}

int G(char symbol)
{

    switch(symbol)
    {

    case '+':
    case '-':
        return 1;


    case '*':
    case '/':
        return 3;


    case '^':
    case '$':
        return 6;

    case '(':
        return 9;

    case ')':
        return 0;

    default:
        return 7;
    }
}

void  infix_postfix(char infix[],char postfix[])
{

    int top,i,j;
    char s[30],symbol;
    top=-1;
    s[++top]='#';
    j=0;
     if(check(infix))
     {
         printf("Valid Expression Continue\n");
     }
     else
     {
         printf("Invalid Expression\n");
         exit(0);
     }
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        while(F(s[top])>G(symbol))
        {
            postfix[j]=s[top--];
            j++;
        }

        if(F(s[top])!=G(symbol))
        {
            s[++top]=symbol;
        }
        else
        {
            top--;
        }
    }

    while(s[top]!='#')
    {
        postfix[j++]=s[top--];
    }
    postfix[j]='\0';
}

int main()
{

    char infix[20];
    char postfix[20];
    printf("Enter the valid Expression\n");
    scanf(" %s",infix);
    infix_postfix(infix,postfix);
    fflush(stdin);
    printf("Postfix Expression is\n");
    printf(" %s\n",postfix);

    return 0;

}
