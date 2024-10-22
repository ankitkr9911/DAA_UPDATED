#include<stdio.h>

int size = -1;
int H[100];

int getMax()
{
    return H[0];
}

void swap(int *a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int parent(int i)
{
    return (i-1)/2;
}

int rightChild(int i)
{
    return 2*i+2;
}

int leftChild(int i)
{
    return 2*i+1;
} 

void shiftUp(int i)
{
    while(i>0 && H[i]>H[parent(i)])
    {
        swap(&H[i],&H[parent(i)]);
        i = parent(i);
    }
}

void insert(int priority)
{
    size = size + 1;
    H[size] = priority;

    shiftUp(size);

}

void shiftDown(int i)
{
    int maxIndex = i;

    int l = leftChild(i);
    if(l<=size && H[l]>H[maxIndex])
    {
        maxIndex = l;
    }

    int r = rightChild(i);
    if(r<=size && H[r]>H[maxIndex])
    {
        maxIndex = r;
    }

    if(maxIndex!=i)
    {
        swap(&H[maxIndex],&H[i]);
        shiftDown(maxIndex);
    }
}

int extractMax()
{
    int result = H[0];
    
    H[0] = H[size];
    size = size -1;

    shiftDown(0);
    return result;
}

void removeElement(int i)
{
    H[i] = getMax() + 1;

    shiftUp(i);
    extractMax();
}

int main()
{
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    printf("Priority Queue: ");
    for(int j=0;j<=size;j++)
    {
        printf("%d ",H[j]);
    }

    printf("\nRemoving 7 \n");
    removeElement(5) ; //5 is the index of 7 

    printf("Priority Queue after removing 7: ");
    for(int j=0;j<=size;j++)
    {
        printf("%d ",H[j]);
    }

    return 0;

}

