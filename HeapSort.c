//
//  HeapSort.c
//  HeapSort
//
//  Created by Daniel on 15/9/8.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "HeapSort.h"
#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1
#define PARENT(i) i/2
#define LENGTH 10

int heapSize;
void max_heapify(int A[],int i)
{
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest;
    if (left <= heapSize && A[left] > A[i])
        largest = left;
    else
        largest = i;
    if (right <= heapSize && A[right] > A[largest])
        largest = right;
    if (largest != i)
    {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        max_heapify(A, largest);
    }
}
void build_max_heap(int A[])
{
    heapSize = LENGTH;
    for (int i = LENGTH/2;i >=1;i--)
        max_heapify(A, i);
}

void heapSort(int A[])
{
    build_max_heap(A);
    for (int i = LENGTH;i>=2;i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i]=temp;
        heapSize -= 1;
        max_heapify(A, 1);
    }
}

int heap_max(int A[])
{
    return A[1];
}

int heap_extract_max(int A[])
{
    if (heapSize < 1)
        printf("%s","heap underflow");
    int max = A[1];
    A[1] = A[heapSize];
    heapSize -= 1;
    max_heapify(A, 1);
    return max;
}

void heap_increase_key(int A[],int i,int key)
{
    if (key < A[i])
        printf("%s","new key is smaller than current key");
    A[i] = key;
    while (i > 1 && A[PARENT(i)] < A[i])
    {
        int temp = A[i];
        A[i] = A[PARENT(i)];
        A[PARENT(i)] = temp;
        i = PARENT(i);
    }
}

void max_heap_insert(int A[],int key)
{
    heapSize +=1;
    A[heapSize] = INT16_MIN;
    heap_increase_key(A, heapSize, key);
}

void heap_delete(int A[],int i)
{
    A[i] = A[heapSize];
    heapSize -= 1;
    int key = A[i];
    if (key <= A[PARENT(i)])
    {
        max_heapify(A, i);
    }
    else
    {
        while (i > 1 && A[PARENT(i)] < A[i])
        {
            int temp = A[i];
            A[i] = A[PARENT(i)];
            A[PARENT(i)] = temp;
            i = PARENT(i);
        }
    }
}