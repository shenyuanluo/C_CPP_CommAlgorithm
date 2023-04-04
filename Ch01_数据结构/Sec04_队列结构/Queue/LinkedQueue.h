//
//  LinkedQueue.h
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueHeader.h"


/** （链式）队列结构 */
typedef struct node {
    NodeData nodeData;                  // 保存结点数据
    struct node* nextNode;              // 保存下一结点的地址
}LQType;


/** 链表头 */
typedef struct _head {
    LQType* headNode;                   // 保存队头结点地址（出队列）
    LQType* tailNode;                   // 保存队尾结点地址（入队列）
    unsigned int lqLength;              // 队列长度
}Head;


/**
 （链式）队列初始化
 
 @return 指向队列的指针变量
 */
Head* LQueueInit();


/**
 空（链式）队列判断
 
 @param pHead 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue LQueueIsEmpty(Head* pHead);


/**
 入（链式）队列
 
 @param pHead 指向队列的指针变量
 @param inData 入队列数据
 @return 参见‘RetValue’
 */
RetValue LQueueIn(Head* pHead, NodeData inData);


/**
 出（链式）队列
 
 @param pHead 指向队列的指针变量
 @param outData 出队列数据
 @return 参见‘RetValue’
 */
RetValue LQueueOut(Head* pHead, NodeData* outData);


/**
 销毁（链式）队列
 
 @param pHead 指向队列的指针变量
 @return 参见‘RetValue’
 */
RetValue LQueueDestroy(Head* pHead);


/**
 读取（链式）队头数据
 
 @param pHead 指向队列的指针变量
 @param peekData 队列顶数据
 @return 参见‘RetValue’
 */
RetValue LQueuePeek(Head* pHead, NodeData* peekData);


/**
 显示队列所有结点数据
 
 @param pHead 队列指针变量
 @return 参见‘RetValue’
 */
RetValue LQueueShowAll(Head* pHead);

#endif /* LinkedQueue_h */
