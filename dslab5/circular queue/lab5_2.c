#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 5
int q[max];
int front=-1;
int rear=-1;
void insert();
int del();
void display();
int main()
{
    int option,val;
    do
    {
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:display\n");
        printf("4:exit\n");
        printf("Enter your option\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            insert();
            break;
        case 2:
            val=del();
            if(val!=-1)
                printf("Item Deleted is %d\n",val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }

    }while(option!=4);
    return 0;
}
void insert()
{
        int num;
        printf("Enter the number to be inserted\n");
        scanf("%d",&num);
        if(front==0&&rear==max-1)
            printf("Overflow\n");
        else if(front==-1&&rear==-1)
        {
            front=0;
            rear=0;
            q[rear]=num;
        }
        else if(rear==max-1&&front!=0)
        {
            rear=0;
            q[rear]=num;
        }
        else if(rear==max-1&&front!=0)
        {
            rear=0;
            q[rear]=num;
        }
        else
        {
            rear++;
            q[rear]=num;
        }
}

int del()
{
    int val;
    if(front==-1&&rear==-1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    val=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==max-1)
            front=0;
        else
            front++;
    }
    return val;
}

void display()
{
    if(front==-1&&rear==-1)
        printf("QUEUQ UNDERFLOW\n");
    else
    {
        if(front<rear)
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d\n",q[i]);
            }
        }
        else
        {
            for(int i=front;i<max;i++)
                printf("%d\n",q[i]);
            for(int i=0;i<=rear;i++)
                printf("%d\n",q[i]);
        }
    }
}




