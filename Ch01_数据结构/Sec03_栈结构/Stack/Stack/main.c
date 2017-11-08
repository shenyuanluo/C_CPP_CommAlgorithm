//
//  main.c
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "SequentialStack.h"


int main()
{
    // 测试
    SSType* pStack;
    NodeData nData, peekData;
    
    printf("栈操作演示开始。。。\n");
    
    // 初始化栈
    pStack = StackInit();
    if (NULL == pStack)
    {
        printf("栈初始化失败！\n");
        
        return 0;
    }
    
    do
    {
        printf("\n请输入需要添加的节点：学号 姓名 年龄\n");
        
        // 清空输入缓冲区
        fflush(stdin);
        
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        
        if (nData.age)       // 若年龄不为 0
        {
            if (Ret_Error == StackPush(pStack, nData))
            {
                break;      // 添加失败，退出循环
            }
        }
        else
        {
            break;          // 若年龄为 0，条件不符合，退出循环
        }
    } while (1);
    
    printf("\n栈中已有的节点为：\n");
    
    StackShowAll(pStack);
    
    printf("出栈操作。。。\n");
    
    if (Ret_YES == StackPop(pStack, &nData))
    {
        printf("出栈节点是：\nkey = %-15s name = %-20s age = %d\n", nData.key, nData.name, nData.age);
    }
    
    printf("\n栈中已有的节点为：\n");
    
    StackShowAll(pStack);
    
    printf("\n查看栈顶节点。。。\n");
    
    if (Ret_YES == StackPeek(pStack, &peekData))
    {
        printf("现在栈顶节点是：\nkey = %-15s name = %-20s age = %d\n", peekData.key, peekData.name, peekData.age);
    }
    
    printf("\n栈中已有的节点为：\n");
    
    StackShowAll(pStack);
    
    printf("\n");
    
    return 0;
}

