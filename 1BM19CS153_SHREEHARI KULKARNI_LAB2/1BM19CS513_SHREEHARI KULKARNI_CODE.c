#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int top=-1;
int s[10];
int item;
void push()
{
    if(top==STACK_SIZE-1)
    {

        printf("STACK OVERFLOW ELEMENT CANNOT BE ADDED\n");
        return;
    }
    top+=1;
    s[top]=item;
}

int pop()
{
    if(top==-1)
    {
        return -1;
    }
    return s[top--];
}
 void display()
 {

     if(top==-1)
     {
         printf("STACK IS EMPTY NO ITEM CAN BE PRINTED\n");
         return;
     }
     else
     {
         for(int i=top;i>=0;i--)
         {
             printf("%d\n",s[i]);
         }
     }

 }
 int main()
 {
     int item_deleted;
     int choice;
     for(;;)
     {
         printf("\n1:push\n2:pop\n3:display\n4:exit\n");
         printf("Enter your choice\n");
         scanf("%d",&choice);
         switch(choice)
         {

         case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            push();
            break;

         case 2:
            item_deleted=pop();
            if(item_deleted==-1)
                printf("Stack is empty\n");
            else{
                printf("Deleted item is %d\n",item_deleted);
            }
            break;

         case 3:
            printf("Elements of stack are \n");
            display();
            break;


         default:
            exit(0);
         }
     }

 }