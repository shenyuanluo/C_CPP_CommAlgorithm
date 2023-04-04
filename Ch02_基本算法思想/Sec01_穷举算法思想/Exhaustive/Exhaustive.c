//
//  Exhaustive.c
//  Exhaustive
//
//  Created by shenyuanluo on 2017/11/16.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "Exhaustive.h"

#pragma mark -- 鸡兔同笼求值
RetValue ExhaustiveAttack(unsigned int headNum, unsigned int footNum, unsigned int* chicken, unsigned int* rabbit)
{
    if (0 == headNum || 0 == footNum)
    {
        return RetFailure;
    }
    for (unsigned int chNum = 0; chNum <= headNum; chNum++)
    {
        unsigned int raNum = headNum - chNum;
        
        if (footNum == chNum * 2 + raNum * 4)
        {
            *chicken = chNum;
            *rabbit  = raNum;
            return RetSuccess;
        }
    }

    return RetFailure;
}
