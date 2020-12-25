#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE getnode(int data)
{
    NODE x=(NODE)malloc(sizeof(struct node));
    x->data=data;
    x->right=NULL;
    x->left=NULL;
    return x;
}
NODE insert(NODE root,int info)
{

    if(root==NULL)
    {
        root=getnode(info);
        return root;
    }
    else if(info<=root->data)
    {
        root->left=insert(root->left,info);
    }
    else
    {
        root->right=insert(root->right,info);
    }
    return root;
}
void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void postorder(NODE root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
}
NODE findmin(NODE root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    return findmin(root->left);
}
NODE delete_node(NODE root,int info)
{
    if(root==NULL)
    {
        return root;
    }
    else if(info<root->data)
    {
        root->left=delete_node(root->left,info);
    }
    else if(info>root->data)
    {
        root->right=delete_node(root->right,info);
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
          free(root);
          root=NULL;
          return root;
        }
        else if(root->left==NULL)
        {
           NODE temp=root;
           root=root->left;
           free(temp);
           return root;
        }
        else if(root->right==NULL)
        {
           NODE temp=root;
           root=root->right;
           free(temp);
           return root;
       }
       else
       {
           NODE temp=findmin(root->right);
           root->data=temp->data;
           root->right=delete_node(root->right,temp->data);
           return root;
       }
    }
}
void display(NODE root,int i)
{
    if(root==NULL)
        return;
    display(root->right,i+1);
    for(int j=1;j<=i;j++)
        printf(" ");
    printf("%d\n",root->data);
    display(root->left,i+1);
}
int getleafcount(NODE root)
{
    NODE current=root;
    if(current==NULL)
        return 0;
    else if(current->right==NULL&&current->left==NULL)
        return 1;
    else
        return (getleafcount(current->left)+getleafcount(current->right));
}
int height(NODE root)
{
    if(root==NULL)
        return -1;
    int left_height=height(root->left);
    int right_height=height(root->right);
    if(left_height>right_height)
        return left_height+1;
    else
        return right_height+1;
}
NODE inorder_successor(NODE root,int data)
{
    if(root==NULL)
    {
        printf("Tree Empty\n");
        return root;
    }
    NODE current=root;
    if(current->right!=NULL)
    {
        NODE temp=findmin(current->right);
    }
    else
    {
        NODE successor=NULL;
        NODE ancestor=root;
        while(current!=ancestor)
        {
            if(current->data<ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
            {
                ancestor=ancestor->right;
            }
        }
        return successor;
    }
}
int main()
{
    NODE root=NULL;
    int data,option,ans;
    do{
    printf("1:Insert\n");
    printf("2:Delete\n");
    printf("3:Preorder\n");
    printf("4:PostOrder\n");
    printf("5:Inorder\n");
    printf("6:Display\n");
    printf("7:Height Of Tree\n");
    printf("8:Exit\n");
    printf("Enter Your Choice\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("Enter The Data To Be Inserted\n");
        scanf("%d",&data);
        root=insert(root,data);
        break;
    case 2:
        printf("Enter the Data To Be Deleted\n");
        scanf("%d",&data);
        root=delete_node(root,data);
        break;
    case 3:
        preorder(root);
        printf("\n");
        break;
    case 4:
        postorder(root);
        printf("\n");
        break;
    case 5:
        inorder(root);
        printf("\n");
        break;
    case 6:
        display(root,1);
        break;
    case 7:
        ans=height(root);
        printf("Height Of Tree Is %d\n",ans);
        break;
    }
    }while(option!=8);

}
