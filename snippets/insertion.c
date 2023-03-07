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

int count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }return c;
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index < 0 || index >count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int main()
{
    int a[]={12,23,34,45,56};
    creation(a,5);
    insert(first,3,67);
    display(first);
}