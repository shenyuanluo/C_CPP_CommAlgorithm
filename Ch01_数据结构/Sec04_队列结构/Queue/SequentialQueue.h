//
//  SequentialQueue.h
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef SequentialQueue_h
#define SequentialQueue_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueHeader.h"


/** 队列的最大长度 */
#define MAX_LEN 100


/** (顺序)队列结构 */
typedef struct {
    NodeData QueueData[MAX_LEN];        // 数据元素
    int head;                           // 队头位置（出队列）
    int tail;                           // 队尾位置（入队列）
}SQType;



/**
 （顺序）队列初始化
 
 @return 指向队列的指针变量
 */
SQType* SQueueInit();



/**
 空（顺序）队列判断
 
 @param pQueue 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue SQueueIsEmpty(SQType* pQueue);



/**
 满（顺序）队列判断
 
 @param pQueue 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue SQueueIsFull(SQType* pQueue);



/**
 （顺序）队列清空
 
 @param pQueue 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue SQueueClear(SQType* pQueue);



/**
 （顺序）队列释放
 
 @param pQueue 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue SQueueFree(SQType* pQueue);



/**
 入（顺序）队列
 
 @param pQueue 指向队列的指针变量
 @param inData 入队列数据
 @return 参见‘RetValue’
 */
RetValue SQueueIn(SQType* pQueue, NodeData inData);




/**
 出（顺序）队列
 
 @param pQueue 指向队列的指针变量
 @param outData 出队列数据
 @return 参见‘RetValue’
 */
RetValue SQueueOut(SQType* pQueue, NodeData* outData);



/**
 读取（顺序）队头结点数据
 
 @param pQueue 指向队列的指针变量
 @param peekData 队列顶数据
 @return 参见‘RetValue’
 */
RetValue SQueuePeek(SQType* pQueue, NodeData* peekData);


/**
 计算队列长度

 @param pQueue 指向队列的指针变量
 @return 队列长度
 */
unsigned int SQueueLength(SQType* pQueue);



/**
 显示（顺序）队列所有结点数据
 
 @param pQueue 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue SQueueShowAll(SQType* pQueue);

#endif /* SequentialQueue_h */
