#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 5
int q[max];
int front=-1,rear=-1;
void insert();
int delete();
void display();
int main()
{

    int option,val;
    do
    {
        printf("**********MAIN MENU***********\n");
        printf("1:INSERT\n");
        printf("2:DELETE\n");
        printf("3:DISPLAY\n");
        printf("4:EXIT\n");
        printf("Enter the option\n");
        scanf("%d",&option);
        switch(option)
        {

        case 1:
            insert();
            break;
        case 2:
            val=delete();
            if(val!=-1)
            {
                printf("Item deleted is %d\n",val);
            }
            break;
        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }while(option!=5);
    return 0;
}

void insert()
{
    int num;
    printf("Enter the number to be inserted\n");
    scanf("%d",&num);
    if(rear==max-1)
    {
        printf("OVERFLOW\n");
    }
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=num;
    }
    else
    {
        rear++;
        q[rear]=num;
    }
}
int delete()
{
    int val;
    if(front==-1||front>rear)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        val=q[front];
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }

        return val;
    }
}
void display()
{
    if(front==-1||front>rear)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
       for(int i=front;i<=rear;i++)
       {
           printf("%d\n",q[i]);
       }
    }

}
