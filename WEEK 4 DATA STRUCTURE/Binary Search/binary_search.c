#include<stdio.h>
int binarysearch(int arr[],int l,int h,int item);
void sort(int a[]);
int n;
int main()
{
    int a[100];
    int val;
    printf("Enter the number of elements of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a);
    printf("***************Array After Sorting is*************\n");
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&val);
    int answer=binarysearch(a,0,n-1,val);
    if(answer==1)
        printf("Element is not present\n");
    else
        printf("Element is present at location %d\n",answer);
}
int binarysearch(int a[],int l,int h,int item)
{
    int mid=(l+h)/2;
    if(a[mid]==item)
        return mid;
    else if(a[mid]>item)
    {
        return binarysearch(a,l,mid-1,item);
    }
    else if(a[mid]<item)
        return binarysearch(a,mid+1,h,item);
    else
    {
        return -1;
    }
}
void sort(int a[])
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


