//
//  SequentialStack.c
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "SequentialStack.h"


#pragma mark -- 栈初始化
SSType* StackInit()
{
    SSType *pStack;
    if (!(pStack = (SSType *)malloc(sizeof(SSType))))
    {
        printf("无法分配栈内存，栈初始化失败！\n");
        return NULL;
    }
    pStack->stackTop = 0;
    return pStack;
}


#pragma mark -- 栈为空判断
RetValue StackIsEmpty(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行为空判断！\n");
        return Ret_Error;
    }
    
    if (0 == pStack->stackTop)
    {
        return Ret_YES;
    }
    else
    {
        return Ret_NO;
    }
}


#pragma mark -- 栈填满判断
RetValue StackIsFull(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行填满判断！\n");
        return Ret_Error;
    }
    
    if (MAX_LEN == pStack->stackTop)
    {
        return Ret_YES;
    }
    else
    {
        return Ret_NO;
    }
}


#pragma mark -- 栈清空
RetValue StackClear(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行栈清空！\n");
        return Ret_Error;
    }
    
    pStack->stackTop = 0;
    return Ret_YES;
}


#pragma mark -- 栈释放
RetValue StackFree(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行栈释放！\n");
        return Ret_Error;
    }
    
    free(pStack);
    return Ret_YES;
}


#pragma mark -- 入栈
RetValue StackPush(SSType* pStack, NodeData nData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法入栈！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsFull(pStack))
    {
        printf("栈已满，无法入栈！\n");
        return Ret_Error;
    }
    
    pStack->stackData[pStack->stackTop] = nData;
    pStack->stackTop++;
    
    return Ret_YES;
}


#pragma mark -- 出栈
RetValue StackPop(SSType* pStack, NodeData* nData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法出栈！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，无法出栈！\n");
        return Ret_Error;
    }
    
    pStack->stackTop--;
    *nData = pStack->stackData[pStack->stackTop];
    
    return Ret_YES;
}


#pragma mark -- 读取栈顶节点数据
RetValue StackPeek(SSType* pStack, NodeData* peekData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法读取栈顶数据！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，栈顶数据不存在！\n");
        return Ret_Error;
    }
    
    *peekData = pStack->stackData[pStack->stackTop - 1];
    
    return Ret_YES;
}


#pragma mark -- 显示栈所有数据
RetValue StackShowAll(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法显示栈所有数据！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，栈数据不存在！\n");
        return Ret_Error;
    }
    
    for (int i = 0; i < pStack->stackTop; i++)
    {
        printf("key = %-15s name = %-20s age = %d\n", pStack->stackData[i].key, pStack->stackData[i].name, pStack->stackData[i].age);
    }
    return Ret_YES;
}
