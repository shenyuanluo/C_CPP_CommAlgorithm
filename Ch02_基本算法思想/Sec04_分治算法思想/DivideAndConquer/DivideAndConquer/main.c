//
//  main.c
//  DivideAndConquer
//
//  Created by shenyuanluo on 2017/11/18.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "DivideAndConquer.h"

/** 最大硬币数量*/
#define MAX_COIN_COUNT 30

int main()
{
    unsigned int coinArr[MAX_COIN_COUNT];
    unsigned int count;
    unsigned int falseNo;
    
    printf("分治算法求解假硬币问题演示：\n");
    printf("请输入硬币的总数：");
    fflush(stdin);
    scanf("%u", &count);
    
    printf("\n请输入硬币的真假：");
    for (int i = 0; i < count; i++)
    {
        scanf("%u", &coinArr[i]);
    }
    
    falseNo = FalseCoin(coinArr, 0, count - 1);
    printf("\n在上述 %d 个硬币中，第 %d 个硬币是假的！\n", count, falseNo);
    
    return 0;
}
