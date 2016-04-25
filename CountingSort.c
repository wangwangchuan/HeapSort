//
//  CountingSort.c
//  HeapSort
//
//  Created by Daniel on 15/9/11.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "CountingSort.h"

void counting_sort(int *A,int *B,int n,int k)
{
    int C[k+1],i,j;
    //初始化
    for (i=0;i<=k;i++)
    {
        C[i] = 0;
    }
    //C数组包含A[j]元素的个数
    for(j=1;j<=n;j++)
    {
        C[A[j]] = C[A[j]]+1;
    }
    //C[i]包含小于或等于i的元素个数
    for(i = 1;i <= k;i++)
    {
        C[i] = C[i] +C[i-1];
    }
    //根据C[i]存储的元素位置，将i值放入B数组中,同时保证稳定性
    for (j=n;j>=1;j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}