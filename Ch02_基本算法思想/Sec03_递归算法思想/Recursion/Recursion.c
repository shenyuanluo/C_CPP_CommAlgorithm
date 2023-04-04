//
//  Recursion.c
//  Recursion
//
//  Created by shenyuanluo on 2017/11/17.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "Recursion.h"


#pragma mark -- 求自然数的阶乘
long Factorial(unsigned int n)
{
    if (1 >= n)
    {
        return 1;
    }
    long fact = Factorial(n - 1);
    
    return n * fact;
}
