#include <stdio.h>

int maxHeap[1000] = {0};
int n = 0;

void csere(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void maxHeapifyUp(int i)
{
    if (i > 1 && maxHeap[i] > maxHeap[i / 2])
    {
        csere(&maxHeap[i], &maxHeap[i / 2]);
        maxHeapifyUp(i / 2);
    }
}

void heapInsert(int x)
{
    maxHeap[n] = x;
    n++;
}

void out()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", maxHeap[i]);
    }
    printf("\n");
}
int main()
{
}