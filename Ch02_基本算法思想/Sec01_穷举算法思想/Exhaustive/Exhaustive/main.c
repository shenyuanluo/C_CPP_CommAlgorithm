//
//  main.c
//  Exhaustive
//
//  Created by shenyuanluo on 2017/11/16.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "Exhaustive.h"

int main()
{
    unsigned int chiken, rabbit, head, foot;
    RetValue ret;
    
    printf("穷举法求鸡兔同笼问题:\n");
    printf("\n请输入头数：");
    fflush(stdin);
    scanf("%u", &head);
    
    printf("\n请输入脚数：");
    fflush(stdin);
    scanf("%u", &foot);
    
    ret = ExhaustiveAttack(head, foot, &chiken, &rabbit);
    if (RetSuccess == ret)
    {
        printf("\n鸡有：%u 只\t兔有： %u 只\n", chiken, rabbit);
    }
    else
    {
        printf("\n无法求解！\n");
    }
    
    return 0;
}
