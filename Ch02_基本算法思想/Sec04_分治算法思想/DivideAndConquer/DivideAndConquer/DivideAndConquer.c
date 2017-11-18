//
//  DivideAndConquer.c
//  DivideAndConquer
//
//  Created by shenyuanluo on 2017/11/18.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "DivideAndConquer.h"


#pragma mark --  求假硬币的编号
unsigned int FalseCoin(unsigned int coinArr[], unsigned int lowNo, unsigned int hightNo)
{
    unsigned int falseNo   = 0;
    unsigned int sumLeft   = 0;
    unsigned int sumCenter = 0;
    unsigned int sumRight  = 0;
    
    if (lowNo + 1 == hightNo)                           // 最后两个硬币
    {
        if (coinArr[lowNo] < coinArr[hightNo])
        {
            falseNo = lowNo + 1;
        }
        else
        {
            falseNo = hightNo + 1;
        }
        return falseNo;
    }
    else if (0 == (hightNo - lowNo + 1) % 2)            // 有偶数个硬币
    {
        int centerNo = lowNo + ((hightNo - lowNo) / 2);
        for (int i = lowNo; i <= centerNo; i++)         // 计算前半部分硬币重量
        {
            sumLeft += coinArr[i];
        }
        
        for (int j = centerNo + 1; j <= hightNo; j++)   // 计算后半部分硬币重量
        {
            sumRight += coinArr[j];
        }
        
        if (sumLeft < sumRight)
        {
            falseNo = FalseCoin(coinArr, lowNo, centerNo);
        }
        else if (sumLeft > sumRight)
        {
            falseNo = FalseCoin(coinArr, centerNo + 1, hightNo);
        }
        else
        {
            printf("计算出错！\n");
        }
        return falseNo;
    }
    else                                                // 有奇数个硬币
    {
        int centerNo = lowNo + ((hightNo - lowNo) / 2);
        for (int i = lowNo; i <= centerNo - 1; i++)     // 计算前半部分硬币的重量
        {
            sumLeft += coinArr[i];
        }
        
        for (int j = centerNo + 1; j <= hightNo; j++)   // 计算后半部分硬币的重量
        {
            sumRight += coinArr[j];
        }
        
        sumCenter = coinArr[centerNo];                  // 中间那枚硬币的重量
        
        if (sumLeft < sumRight)
        {
            falseNo = FalseCoin(coinArr, lowNo, centerNo - 1);
        }
        else if (sumLeft > sumRight)
        {
            falseNo = FalseCoin(coinArr, centerNo + 1, hightNo);
        }
        else
        {
            falseNo = centerNo + 1;
        }
        
        return falseNo;
    }
}
