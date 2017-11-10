//
//  SequentialQueue.c
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "SequentialQueue.h"


#pragma mark -- 队列初始化
SQType* SQueueInit()
{
    SQType* pQueue;
    if (!(pQueue = (SQType*)malloc(sizeof(SQType))))
    {
        printf("无法分配队列内存，（顺序）队列初始化失败！\n");
        return NULL;
    }
    pQueue->head = 0;
    pQueue->tail = 0;
    return pQueue;
}


#pragma mark -- 空（顺序）队列判断
RetValue SQueueIsEmpty(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法进行空队列判断！\n");
        return RetError;
    }
    
    if (pQueue->tail == pQueue->head)
    {
        return RetSuccess;
    }
    else
    {
        return RetFailure;
    }
}


#pragma mark -- 满（顺序）队列判断
RetValue SQueueIsFull(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法进行满队列判断！\n");
        return RetError;
    }
    
    if (MAX_LEN == pQueue->tail)
    {
        return RetSuccess;
    }
    else
    {
        return RetFailure;
    }
}


#pragma mark -- 队列清空
RetValue SQueueClear(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法进行队列清空！\n");
        return RetError;
    }
    
    pQueue->head = 0;
    pQueue->tail = 0;
    return RetSuccess;
}


#pragma mark -- 队列释放
RetValue SQueueFree(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法进行队列释放！\n");
        return RetError;
    }
    
    free(pQueue);
    return RetSuccess;
}


#pragma mark -- 入队列
RetValue SQueueIn(SQType* pQueue, NodeData inData)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法入队列！\n");
        return RetError;
    }
    if (RetSuccess == SQueueIsFull(pQueue))
    {
        printf("（顺序）队列已满，无法入队列！\n");
        return RetFailure;
    }
    
    pQueue->QueueData[pQueue->tail] = inData;
    pQueue->tail++;
    
    return RetSuccess;
}


#pragma mark -- 出队列
RetValue SQueueOut(SQType* pQueue, NodeData* outData)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法出队列！\n");
        return RetError;
    }
    if (RetSuccess == SQueueIsEmpty(pQueue))
    {
        printf("（顺序）队列为空，无法出队列！\n");
        return RetFailure;
    }
    
    *outData = pQueue->QueueData[pQueue->head];
    pQueue->head++;
    
    return RetSuccess;
}


#pragma mark -- 读取队头结点数据
RetValue SQueuePeek(SQType* pQueue, NodeData* peekData)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法读取队列顶数据！\n");
        return RetError;
    }
    if (RetSuccess == SQueueIsEmpty(pQueue))
    {
        printf("（顺序）队列为空，队列顶数据不存在！\n");
        return RetFailure;
    }
    
    *peekData = pQueue->QueueData[pQueue->head];
    
    return RetSuccess;
}


#pragma mark -- 计算队列长度
unsigned int SQueueLength(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法计算队列长度！\n");
        return 0;
    }
    unsigned int qLen = pQueue->tail - pQueue->head;

    return qLen;
}


#pragma mark -- 显示队列所有数据
RetValue SQueueShowAll(SQType* pQueue)
{
    if (NULL == pQueue)
    {
        printf("（顺序）队列指针不存在，无法显示队列所有数据！\n");
        return RetError;
    }
    if (RetSuccess == SQueueIsEmpty(pQueue))
    {
        printf("（顺序）队列为空，队列数据不存在！\n");
        return RetFailure;
    }
    
    for (int i = pQueue->head; i < pQueue->tail; i++)
    {
        printf("key = %-15s name = %-20s age = %d\n", pQueue->QueueData[i].key, pQueue->QueueData[i].name, pQueue->QueueData[i].age);
    }
    return RetSuccess;
}
