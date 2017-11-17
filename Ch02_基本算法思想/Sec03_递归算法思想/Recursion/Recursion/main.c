//
//  main.c
//  Recursion
//
//  Created by shenyuanluo on 2017/11/17.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "Recursion.h"

int main()
{
    int n;
    printf("请输入一个要求阶乘的自然数：");
    fflush(stdin);
    scanf("%d", &n);
    
    long fact = Factorial(n);
    
    printf("\n%d 的阶乘结果为：%ld\n", n, (long)fact);
    
    return 0;
}
