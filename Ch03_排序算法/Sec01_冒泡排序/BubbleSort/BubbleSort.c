//
//  BubbleSort.c
//  BubbleSort
//
//  Created by shenyuanluo on 2017/11/19.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "BubbleSort.h"


RetValue BubbleSort(int* array, int len, SortType type)
{
    if (NULL == array || 0 >= len)
    {
        printf("数组不存在，无法对其进行冒泡排序！\n");
        return RetError;
    }
    
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (SortASC == type)
            {
                if (array[i] > array[j])
                {
                    int tem  = array[i];
                    array[i] = array[j];
                    array[j] = tem;
                }
            }
            else if (SortDES == type)
            {
                if (array[i] < array[j])
                {
                    int tem  = array[i];
                    array[i] = array[j];
                    array[j] = tem;
                }
            }
        }
        printf("第 %d 步结果：\t", i + 1);
        for (int k = 0; k < len; k++)
        {
            printf("%d\t", array[k]);
        }
        printf("\n");
    }
    return RetSuccess;
}
