//
//  InsertSort.c
//  HeapSort
//
//  Created by Daniel on 15/9/9.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include "InsertSort.h"


void InsertSort(int A[],int p,int r)
{
    for (int i = p + 1;i <= r;i++)
    {
        int temp = A[i];
        int j = i;
        while(A[j-1] > temp)
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
    
}