#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* Q)
{
    if(Q->f==Q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue* Q)
{
    if(Q->r==Q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * Q,int value)
{
    if(isFull(Q))
    {
        printf("Queue is Full.\n");
    }
    else{
        Q->r++;
        Q->arr[Q->r] = value;
    }
}

int dequeue(struct queue* Q)
{
    int a= -1;
    if(isEmpty(Q))
    {
        printf("Queue is Empty.\n");
    }
    else{
        Q->f++;
        a = Q->arr[Q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    int node;
    int i=1;//source
    int visited[5] = {0};
    int a[5][5] = {
        {0,1,1,1,1},
        {1,0,0,0,0},
        {1,0,0,0,0},
        {1,0,0,0,0}
    };
    printf("%d ",i);
    visited[i] = 1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
        int node = dequeue(&q);
        for(int j=0;j<7;j++)
        {
            if(a[node][j] == 1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
    }

    return 0;
}
