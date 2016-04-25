//
//  QuickSort.c
//  HeapSort
//
//  Created by Daniel on 15/9/8.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "QuickSort.h"
#include <stdlib.h>
#include <time.h>

int partition(int A[],int p,int r);
void exchange(int *a,int *b);
int random_custom(int p,int q);
void quickSort(int A[],int p,int r)
{
    if (p < r)
    {
        int q = partition(A,p,r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int partition(int A[],int p,int r)
{
    int x = A[r];
    int i = p-1;
    for (int j = p;j <= r-1;j++)
    {
        if (A[j] <= x )
        {
            i += 1;
            exchange(&A[i],&A[j]);
        }
    }
    exchange(&A[i+1],&A[r]);
    return i+1;
}

void exchange(int *a,int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

//快速排序的随机化版本

int randomized_partition(int A[],int p,int r)
{
    int i = random_custom(p, r);
    exchange(&A[i], &A[r]);
    return partition(A, p, r);
}

void randomized_quickSort(int A[],int p,int r)
{
    if (p < r)
    {
        int q = randomized_partition(A, p, r);
        randomized_quickSort(A, p, q-1);
        randomized_quickSort(A, q+1, r);
    }
}

int random_custom(int p,int q)
{
    srand((unsigned)time(NULL));
    int temp = rand()%(q-p+1) + p;
    return temp;
}

//配合插入排序，当子数组小于一个k值时，利用插入排序
int k =4;
void quick_insert_sort(int *A,int p,int r)
{
    if (r - p >= k)
    {
        int q = partition(A,p,r);
        quick_insert_sort(A, p, q-1);
        quick_insert_sort(A, q+1, r);
    }
}
