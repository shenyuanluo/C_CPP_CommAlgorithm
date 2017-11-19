//
//  BubbleSort.h
//  BubbleSort
//
//  Created by shenyuanluo on 2017/11/19.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

#include <stdio.h>


/** 冒泡排序操作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetSuccess          = 0,            // 操作成功
} RetValue;


/** 排序类型 */
typedef enum {
    SortASC             = 0,            // 升序
    SortDES             = 1,            // 降序
}SortType;


/**
 冒泡排序

 @param array 需排序的数组
 @param len 数组长度
 @param type 参见'SortType'
 @return 参见‘RetValue’
 */
RetValue BubbleSort(int* array, int len, SortType type);

#endif /* BubbleSort_h */
