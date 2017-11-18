//
//  Probability.c
//  Probability
//
//  Created by shenyuanluo on 2017/11/18.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "Probability.h"
#include <stdlib.h>
#include <time.h>


#pragma mark --  蒙特卡罗算法计算圆周率 π
double MonteCarloPI(int pointCount)
{
    double approximatePi;
    double x, y;
    int sum = 0;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < pointCount; i++)
    {
        x = (double)rand()/RAND_MAX;            // 产生 0 ~ 1 之间的一个随机数
        y = (double)rand()/RAND_MAX;            // 产生 0 ~ 1 之间的一个随机数
        if (1 >= x * x + y * y)
        {
            sum++;                              // 统计落在圆内的点
        }
    }
    approximatePi = 4.0 * sum / pointCount;     // 计算 π 近似值
    
    return approximatePi;
}
