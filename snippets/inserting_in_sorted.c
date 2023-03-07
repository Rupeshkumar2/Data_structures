#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

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

void display(struct Node *p)
{
    while (p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    
}

void sortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else{
        while(p && p->data < x)
        {
            q=p;
            p=p->next;
        }if(p==first)
        {
            t->next=first;
            first=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{
    int a[]={12,23,34,45,56};
    creation(a,5);
    sortedInsert(first,33);
    display(first);
    return 0;
}