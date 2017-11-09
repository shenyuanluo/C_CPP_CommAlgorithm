//
//  main.c
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "SequentialStack.h"
#include "LinkedStack.h"


#pragma mark -- （顺序）栈测试
void test1()
{
    // 测试
    SSType* pStack;
    NodeData nData, peekData;
    
    printf("（顺序）栈操作演示开始。。。\n");
    
    // 初始化栈
    pStack = SStackInit();
    if (NULL == pStack)
    {
        printf("（顺序）栈初始化失败！\n");
        
        return;
    }
    
    do
    {
        printf("\n请输入需要添加的结点：学号 姓名 年龄\n");
        
        // 清空输入缓冲区
        fflush(stdin);
        
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        
        if (nData.age)       // 若年龄不为 0
        {
            if (RetError == SStackPush(pStack, nData))
            {
                break;      // 添加失败，退出循环
            }
        }
        else
        {
            break;          // 若年龄为 0，条件不符合，退出循环
        }
    } while (1);
    
    printf("\n（顺序）栈中已有的结点为：\n");
    
    SStackShowAll(pStack);
    
    printf("出（顺序）栈操作。。。\n");
    
    if (RetSuccess == SStackPop(pStack, &nData))
    {
        printf("出（顺序）栈结点是：\nkey = %-15s name = %-20s age = %d\n", nData.key, nData.name, nData.age);
    }
    
    printf("\n（顺序）栈中已有的结点为：\n");
    
    SStackShowAll(pStack);
    
    printf("\n查看（顺序）栈顶结点。。。\n");
    
    if (RetSuccess == SStackPeek(pStack, &peekData))
    {
        printf("现在（顺序）栈顶结点是：\nkey = %-15s name = %-20s age = %d\n", peekData.key, peekData.name, peekData.age);
    }
    
    printf("\n（顺序）栈中已有的结点为：\n");
    
    SStackShowAll(pStack);
    
    printf("\n");
}


#pragma mark -- （链式）栈测试
void test2()
{
    // 测试
    Head* pHead;
    NodeData nData, peekData;
    
    printf("(链式)栈操作演示开始。。。\n");
    
    // 初始化栈
    pHead = LStackInit();
    if (NULL == pHead)
    {
        printf("(链式)栈初始化失败！\n");
        
        return;
    }
    
    do
    {
        printf("\n请输入需要添加的结点：学号 姓名 年龄\n");
        
        // 清空输入缓冲区
        fflush(stdin);
        
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        
        if (nData.age)       // 若年龄不为 0
        {
            if (RetError == LStackPush(pHead, nData))
            {
                break;      // 添加失败，退出循环
            }
        }
        else
        {
            break;          // 若年龄为 0，条件不符合，退出循环
        }
    } while (1);
    
    printf("\n栈中已有的结点为：\n");
    
    LStackShowAll(pHead);
    
    printf("（链式）出栈操作。。。\n");
    
    if (RetSuccess == LStackPop(pHead, &nData))
    {
        printf("出（链式）栈结点是：\nkey = %-15s name = %-20s age = %d\n", nData.key, nData.name, nData.age);
    }
    
    printf("\n（链式）栈中已有的结点为：\n");
    
    LStackShowAll(pHead);
    
    printf("\n查看（链式）栈顶结点。。。\n");
    
    if (RetSuccess == LStackPeek(pHead, &peekData))
    {
        printf("现在（链式）栈顶结点是：\nkey = %-15s name = %-20s age = %d\n", peekData.key, peekData.name, peekData.age);
    }
    
    printf("\n（链式）栈中已有的结点为：\n");
    
    LStackShowAll(pHead);
    
    printf("\n");
}



int main()
{
    test2();
    
    return 0;
}

