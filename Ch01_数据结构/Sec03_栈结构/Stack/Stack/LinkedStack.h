//
//  LinkedStack.h
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedStack_h
#define LinkedStack_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StackHeader.h"



/** （链式）栈结构 */
typedef struct node {
    NodeData nodeData;                  // 保存结点数据
    struct node* nextNode;              // 保存下一结点的地址
}LSType;


/** 链表头 */
typedef struct _head {
    LSType* headNode;                   // 保存链表头结点地址
    LSType* tailNode;                   // 保存链表尾结点地址
    unsigned int clLength;              // 链表长度
}Head;


/**
 （链式）栈初始化

 @return 指向栈的指针变量
 */
Head* LStackInit();


/**
 入（链式）栈

 @param pHead 指向栈的指针变量
 @param inData 入栈数据
 @return 参见‘RetValue’
 */
RetValue LStackPush(Head* pHead, NodeData inData);


/**
 出（链式）栈

 @param pHead 指向栈的指针变量
 @param outData 出栈数据
 @return 参见‘RetValue’
 */
RetValue LStackPop(Head* pHead, NodeData* outData);


/**
 判断（链式）栈是否为空

 @param pHead 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue LStackIsEmpty(Head* pHead);


/**
 销毁（链式）栈

 @param pHead 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue LStackDestroy(Head* pHead);


/**
 读取（链式）栈顶数据）

 @param pHead 指向栈的指针变量
 @param peekData 栈顶数据
 @return 参见‘RetValue’
 */
RetValue LStackPeek(Head* pHead, NodeData* peekData);


/**
 显示栈所有结点数据
 
 @param pHead 栈指针变量
 @return 参见‘RetValue’
 */
RetValue LStackShowAll(Head* pHead);


#endif /* LinkedStack_h */
