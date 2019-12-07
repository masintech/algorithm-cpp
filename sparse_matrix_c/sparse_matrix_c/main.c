//
//  main.c
//  sparse_matrix_c
//
//  Created by Marcus Jian on 2019/12/6.
//  Copyright © 2019 Marcus Jian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    int i;printf("Eneter Dimensions");
    scanf("%d%d",&s->m,&s->n);
    printf("Number of non-zero");
    scanf("%d",&s->num);
    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
    printf("Enter non-zero Elements");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->ele[i].i, &s->ele[i].j,&s->ele[i].x);
}

void display(struct Sparse s)
{
    int i, j, k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

add
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Sparse s;
    create(&s);
    display(s);
        
    
    return 0;
}
