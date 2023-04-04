//
//  Derivation.c
//  Derivation
//
//  Created by shenyuanluo on 2017/11/16.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "Derivation.h"


#pragma mark -- 斐波那契数列求和
unsigned int Fibonacci(unsigned int count)
{
    if (0 == count)
    {
        return 0;
    }
    if (1 == count || 2 == count)
    {
        return 1;
    }
    unsigned int one, two;
    one = Fibonacci(count - 1);
    two = Fibonacci(count - 2);
    
    return one + two;
}
