//
//  main.c
//  Derivation
//
//  Created by shenyuanluo on 2017/11/16.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "Derivation.h"


int main()
{
    int n, num;

    printf("递推算法求兔子产仔问题！\n");
    printf("请输入时间：");
    fflush(stdin);
    scanf("%d", &n);
    
    num = Fibonacci(n);
    printf("\n经过 %d 个月，功能繁殖 %d 对兔子！\n", n, num);
    
    
    return 0;
}
