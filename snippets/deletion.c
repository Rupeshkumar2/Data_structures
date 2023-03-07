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

void display(struct Node *p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
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

int deletion(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 0 && index > count(p))
        return x;
    if(index==1)
    {
        q=first;
        x=first->data;
        free(q);
        return x;
    }else{
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int main()
{
    int a[]={12,23,34,45,56};
    creation(a,5);
    printf("deleted element is :%d\n",deletion(first,2));
    display(first);
}