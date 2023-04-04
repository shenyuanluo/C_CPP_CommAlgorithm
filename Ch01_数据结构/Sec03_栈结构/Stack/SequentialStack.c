//
//  SequentialStack.c
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "SequentialStack.h"


#pragma mark -- 栈初始化
SSType* SStackInit()
{
    SSType* pStack;
    if (!(pStack = (SSType*)malloc(sizeof(SSType))))
    {
        printf("无法分配栈内存，（顺序）栈初始化失败！\n");
        return NULL;
    }
    pStack->stackTop = 0;
    return pStack;
}


#pragma mark -- 栈为空判断
RetValue SStackIsEmpty(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法进行空栈判断！\n");
        return RetError;
    }
    
    if (0 == pStack->stackTop)
    {
        return RetSuccess;
    }
    else
    {
        return RetFailure;
    }
}


#pragma mark -- 栈填满判断
RetValue SStackIsFull(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法进行满栈判断！\n");
        return RetError;
    }
    
    if (MAX_LEN == pStack->stackTop)
    {
        return RetSuccess;
    }
    else
    {
        return RetFailure;
    }
}


#pragma mark -- 栈清空
RetValue SStackClear(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法进行栈清空！\n");
        return RetError;
    }
    
    pStack->stackTop = 0;
    return RetSuccess;
}


#pragma mark -- 栈释放
RetValue SStackFree(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法进行栈释放！\n");
        return RetError;
    }
    
    free(pStack);
    return RetSuccess;
}


#pragma mark -- 入栈
RetValue SStackPush(SSType* pStack, NodeData inData)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法入栈！\n");
        return RetError;
    }
    if (RetSuccess == SStackIsFull(pStack))
    {
        printf("（顺序）栈已满，无法入栈！\n");
        return RetFailure;
    }
    
    pStack->stackData[pStack->stackTop] = inData;
    pStack->stackTop++;
    
    return RetSuccess;
}


#pragma mark -- 出栈
RetValue SStackPop(SSType* pStack, NodeData* outData)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法出栈！\n");
        return RetError;
    }
    if (RetSuccess == SStackIsEmpty(pStack))
    {
        printf("（顺序）栈为空，无法出栈！\n");
        return RetFailure;
    }
    
    pStack->stackTop--;
    *outData = pStack->stackData[pStack->stackTop];
    
    return RetSuccess;
}


#pragma mark -- 读取栈顶结点数据
RetValue SStackPeek(SSType* pStack, NodeData* peekData)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法读取栈顶数据！\n");
        return RetError;
    }
    if (RetSuccess == SStackIsEmpty(pStack))
    {
        printf("（顺序）栈为空，栈顶数据不存在！\n");
        return RetFailure;
    }
    
    *peekData = pStack->stackData[pStack->stackTop - 1];
    
    return RetSuccess;
}


#pragma mark -- 显示栈所有数据
RetValue SStackShowAll(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("（顺序）栈指针不存在，无法显示栈所有数据！\n");
        return RetError;
    }
    if (RetSuccess == SStackIsEmpty(pStack))
    {
        printf("（顺序）栈为空，栈数据不存在！\n");
        return RetFailure;
    }
    
    for (int i = 0; i < pStack->stackTop; i++)
    {
        printf("key = %-15s name = %-20s age = %d\n", pStack->stackData[i].key, pStack->stackData[i].name, pStack->stackData[i].age);
    }
    return RetSuccess;
}
