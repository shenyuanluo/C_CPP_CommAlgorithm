//
//  LinkedQueue.c
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "LinkedQueue.h"


#pragma mark -- （链式）队列初始化
Head* LQueueInit()
{
    Head* pHead;
    if (!(pHead = (Head*)malloc(sizeof(Head))))
    {
        printf("无法分配队列头指针内存，（链式）队列初始化失败！\n");
        return NULL;
    }
    pHead->headNode = NULL;
    pHead->tailNode = NULL;
    pHead->lqLength = 0;
    
    return pHead;
}


#pragma mark -- 空（链式）队列判断
RetValue LQueueIsEmpty(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("（链式）队列指针不存在，无法进行为空判断！\n");
        return RetError;
    }
    if (0 == pHead->lqLength)
    {
        return RetSuccess;
    }
    return RetFailure;
}


#pragma mark -- 入（链式）队列
RetValue LQueueIn(Head* pHead, NodeData inData)
{
    if (NULL == pHead)
    {
        printf("（链式）队列指针不存在，无法入队列\n");
        return RetError;
    }
    LQType* newNode;
    if (!(newNode = (LQType*) malloc(sizeof(LQType))))
    {
        printf("新添加结点内存申请失败，无法入队列！\n");
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
    pHead->lqLength++;
    
    return RetSuccess;
}


#pragma mark -- 出（链式）队列
RetValue LQueueOut(Head* pHead, NodeData* outData)
{
    if (NULL == pHead)
    {
        printf("（链式）队列指针不存在，无法入队列\n");
        return RetError;
    }
    if (RetSuccess == LQueueIsEmpty(pHead))
    {
        printf("队列内无结点，无法出队列！\n");
        return RetFailure;
    }
    
    memcpy(outData, &pHead->headNode->nodeData, sizeof(NodeData));
    
    LQType* deleteNode = pHead->headNode;
    
    pHead->headNode = pHead->headNode->nextNode;
    pHead->lqLength--;
    
    free(deleteNode);
    
    return RetSuccess;
}


#pragma mark -- 销毁（链式）队列
RetValue LQueueDestroy(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("（链式）队列指针不存在，无法销毁队列\n");
        return RetError;
    }
    LQType* deleteNode;
    while (pHead->headNode)
    {
        deleteNode      = pHead->headNode;
        pHead->headNode = pHead->headNode->nextNode;
        free(deleteNode);
    }
    pHead->tailNode = NULL;
    pHead->headNode = NULL;
    free(pHead);
    
    return RetSuccess;
}


#pragma mark -- 读取（链式）队头数据
RetValue LQueuePeek(Head* pHead, NodeData* peekData)
{
    if (NULL == pHead)
    {
        printf("（链式）队列指针不存在，无法读取队列顶数据！\n");
        return RetError;
    }
    if (RetSuccess == LQueueIsEmpty(pHead))
    {
        printf("（链式）队列为空，队列顶数据不存在！\n");
        return RetFailure;
    }
    
    *peekData = pHead->headNode->nodeData;
    
    return RetSuccess;
}


#pragma mark -- 显示（链式）队列所有结点数据
RetValue LQueueShowAll(Head* pHead)
{
    if (NULL == pHead)
    {
        printf("(链式)队列指针不存在，无法显示队列所有数据！\n");
        return RetError;
    }
    if (RetSuccess == LQueueIsEmpty(pHead))
    {
        printf("（链式）队列为空，队列数据不存在！\n");
        return RetFailure;
    }
    LQType* tempHead = pHead->headNode;
    while (tempHead)
    {
        printf("key = %-15s name = %-20s age = %d\n", tempHead->nodeData.key, tempHead->nodeData.name, tempHead->nodeData.age);
        tempHead = tempHead->nextNode;
    }
    return RetSuccess;
}
