//
//  FindSort.c
//  HeapSort
//
//  Created by Daniel on 15/9/18.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "FindSort.h"
#include "QuickSort.h"

int randomized_select(int *A,int p,int r,int i)
{
    if (p==r)
    {
        return A[p];
    }
    int q = randomized_partition(A, p, r);
    int k = q-p+1;
    if (i == k)  //the pivot value is the answer
    {
        return A[q];
    }
    else if (i < k)
    {
        return randomized_select(A, p, q-1, i);
    }
    else
    {
        return randomized_select(A, q+1, r, i-k);
    }
        
}