//
//  main.c
//  HeapSort
//
//  Created by Daniel on 15/9/1.
//  Copyright (c) 2015年 Daniel. All rights reserved.
//

#include <stdio.h>
#include "QuickSort.h"
#include "InsertSort.h"
#include "CountingSort.h"
#include "FindSort.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[9]={INT16_MAX,2,6,3,0,10,8,1,12};
    int target = randomized_select(array, 0, 8,7);
        printf("%d--",target);
    return 0;
}

