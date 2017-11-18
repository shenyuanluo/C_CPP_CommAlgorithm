//
//  main.c
//  Probability
//
//  Created by shenyuanluo on 2017/11/18.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "Probability.h"

int main()
{
    int count;
    double approxiPi;
    
    printf("蒙特卡罗概率算法计算 π !\n");
    printf("请输入撒点的数量：");
    fflush(stdin);
    scanf("%d", &count);
    
    approxiPi = MonteCarloPI(count);
    
    printf("\nπ = %f\n", approxiPi);
    
    return 0;
}
