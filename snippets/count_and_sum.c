#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void creation(int a[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    
    for(int i=1;i<n;i++)
    {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
    }
}

void display(struct Node*p)
{
    while(p)
    {
        printf("elements:%d\n",p->data);
        p=p->next;
    }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }return l;
}

int sum(struct Node *p)
{
    int s=0;
    while(p)
    {
        s+=p->data;
        p=p->next;
    }return s;
}

int main()
{
    int a[]={12,23,34,45,56};
    creation(a,5);
    display(first);

    printf("the sum of elements are: %d\n",sum(first));
    printf("no of elements are : %d",count(first));
}