//
//  QuickSort.h
//  HeapSort
//
//  Created by Daniel on 15/9/8.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#ifndef __HeapSort__QuickSort__
#define __HeapSort__QuickSort__

#include <stdio.h>

void quickSort(int A[],int p,int r);
void quick_insert_sort(int *A,int p,int r);
void randomized_quickSort(int A[],int p,int r);
int randomized_partition(int A[],int p,int r);
void exchange(int *a,int *b);
#endif /* defined(__HeapSort__QuickSort__) */

