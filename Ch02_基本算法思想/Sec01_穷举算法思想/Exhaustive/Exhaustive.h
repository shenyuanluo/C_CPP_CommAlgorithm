//
//  Exhaustive.h
//  Exhaustive
//
//  Created by shenyuanluo on 2017/11/16.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef Exhaustive_h
#define Exhaustive_h

#include <stdio.h>


/** 函数返回值 */
typedef enum {
    RetFailure          = 0,            // 失败
    RetSuccess          = 1,            // 成功
}RetValue;


/**
 鸡兔同笼求值

 @param headNum 头的数量
 @param footNum 脚的数量
 @param chicken 鸡的数量
 @param rabbit 兔的数量
 @return 参见‘RetValue’
 */
RetValue ExhaustiveAttack(unsigned int headNum, unsigned int footNum, unsigned int* chicken, unsigned int* rabbit);

#endif /* Exhaustive_h */
