//
//  main.c
//  linked_list_create_display
//
//  Created by Marcus Jian on 2019/12/18.
//  Copyright © 2019 Marcus Jian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data =A[i];
        t->next = NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}


int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum (struct Node *p)
{
    if(p!=NULL)
        return Rsum(p->next)+p->data;
    else
        return 0;
  
}
int main(int argc, const char * argv[]) {
    int A[] ={3,5,7,10,24,29,33,45};
    create(A,8);
    printf("Length is %d\n\n",Rcount(first));
    printf("Sum is %d\n\n",Rsum(first));
    Display(first);
    return 0;
}
