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

struct Node * lsearch(struct Node *p,int key)
{
    struct Node *q;
    while(p)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int main()
{
    int a[]={12,23,34,45,56};
    creation(a,5);
    struct Node *temp;
    temp=lsearch(first,34);
    printf("the search is:%d\n",temp->data);
    display(first);
}