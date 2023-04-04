//
//  main.c
//  BubbleSort
//
//  Created by shenyuanluo on 2017/11/19.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "BubbleSort.h"
#include <time.h>
#include <stdlib.h>


#define ARRAY_LEN 6

int main()
{
    int array[ARRAY_LEN];
    
    srand((unsigned)time(NULL));                // 随机种子
    
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        array[i] = rand() / (RAND_MAX * 0.01);  // 初始化数组，产生 0 ~ 100 之间的随机数
    }
    
    printf("排序前数组为：\t");
    for (int j = 0; j < ARRAY_LEN; j++)
    {
        printf("%d\t", array[j]);
    }
    printf("\n");
    
    if (RetSuccess == BubbleSort(array, ARRAY_LEN, SortDES))
    {
        printf("排序后数组为：\t");
        for (int j = 0; j < ARRAY_LEN; j++)
        {
            printf("%d\t", array[j]);
        }
        printf("\n");
        
    }
    else
    {
        printf("数组排序失败！\n");
    }
    
    return 0;
}
