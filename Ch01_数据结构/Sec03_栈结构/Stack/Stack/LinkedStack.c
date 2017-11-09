//
//  LinkedStack.c
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "LinkedStack.h"


#pragma mark -- （链式）栈初始化
Head* LStackInit()
{
    Head* pHead;
    if (!(pHead = (Head*)malloc(sizeof(Head))))
    {
        printf("无法分配栈头指针内存，（链式）栈初始化失败！\n");
        return NULL;
    }
    pHead->headNode = NULL;
    pHead->tailNode = NULL;
    pHead->clLength = 0;
    
    return pHead;
}


#pragma mark -- 入（链式）栈
RetValue LStackPush(Head* pHead, NodeData inData)
{
    if (NULL == pHead)
    {
        printf("（链式）栈指针不存在，无法入栈\n");
        return RetError;
    }
    LSType* newNode;
    if (!(newNode = (LSType*) malloc(sizeof(LSType))))
    {
        printf("新添加结点内存申请失败，无法入栈！\n");
        return RetFailure;
    }
    newNode->nodeData = inData;
    newNode->nextNode = NULL;
    if (NULL == pHead->tailNode)
    {
        pHead->headNode = newNode;
    }
    else
    {
        pHead->tailNode->nextNode = newNode;
    }
    pHead->tailNode = newNode;
    pHead->clLength++;
    
    return RetSuccess;
}


#pragma mark -- 出（链式）栈
RetValue LStackPop(Head* pHead, NodeData* outData)
{
    if (NULL == pHead)
    {
        printf("（链式）栈指针不存在，无法入栈\n");
        return RetError;
    }
    if (NULL == pHead->tailNode)
    {
        printf("栈内无结点，无法出栈！\n");
        return RetFailure;
    }

    memcpy(outData, &pHead->tailNode->nodeData, sizeof(NodeData));
    
    LSType* tempHead = pHead->headNode;
    LSType* deleteNode = pHead->headNode;
    while (NULL != deleteNode->nextNode)
    {
        tempHead   = deleteNode;
        deleteNode = tempHead->nextNode;
    }
    tempHead->nextNode = NULL;
    pHead->tailNode    = tempHead;
    pHead->clLength--;
    
    free(deleteNode);
    
    return RetSuccess;
}


#pragma mark -- 判断（链式）栈是否为空
RetValue LStackIsEmpty(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("（链式）栈指针不存在，无法进行为空判断！\n");
        return RetError;
    }
    if (0 == pHead->clLength)
    {
        return RetSuccess;
    }
    return RetFailure;
}


#pragma mark -- 销毁（链式）栈
RetValue LStackDestroy(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("（链式）栈指针不存在，无法销毁栈\n");
        return RetError;
    }
    LSType* tempHead;
    while (pHead->headNode)
    {
        tempHead = pHead->headNode;
        pHead->headNode = pHead->headNode->nextNode;
        free(tempHead);
    }
    pHead->tailNode = NULL;
    pHead->headNode = NULL;
    free(pHead);
    
    return RetSuccess;
}


#pragma mark -- 读取（链式）栈顶数据
RetValue LStackPeek(Head* pHead, NodeData* peekData)
{
    if (NULL == pHead)
    {
        printf("（链式）栈指针不存在，无法读取栈顶数据！\n");
        return RetError;
    }
    if (RetSuccess == LStackIsEmpty(pHead))
    {
        printf("（链式）栈为空，栈顶数据不存在！\n");
        return RetError;
    }
    
    *peekData = pHead->tailNode->nodeData;
    
    return RetSuccess;
}


#pragma mark -- 显示（链式）栈所有结点数据
RetValue LStackShowAll(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("(链式)栈指针不存在，无法显示栈所有数据！\n");
        return RetError;
    }
    if (RetSuccess == LStackIsEmpty(pHead))
    {
        printf("（链式）栈为空，栈数据不存在！\n");
        return RetFailure;
    }
    LSType* tempHead = pHead->headNode;
    while (tempHead)
    {
        printf("key = %-15s name = %-20s age = %d\n", tempHead->nodeData.key, tempHead->nodeData.name, tempHead->nodeData.age);
        tempHead = tempHead->nextNode;
    }
    return RetSuccess;
}
