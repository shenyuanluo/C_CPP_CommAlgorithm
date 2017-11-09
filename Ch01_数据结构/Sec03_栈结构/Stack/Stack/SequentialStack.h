//
//  SequentialStack.h
//  Stack
//
//  Created by shenyuanluo on 2017/11/8.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef SequentialStack_h
#define SequentialStack_h

#include <stdio.h>
#include <stdlib.h>
#include "StackHeader.h"


/** 栈的最大长度 */
#define MAX_LEN 100


/** (顺序)栈结构 */
typedef struct {
    NodeData stackData[MAX_LEN];        // 数据元素
    int stackTop;                       // 栈顶位置
}SSType;



/**
 （顺序）栈初始化
 
 @return 指向栈的指针变量
 */
SSType* SStackInit();



/**
 判断（顺序）栈是否为空
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue SStackIsEmpty(SSType* pStack);



/**
 判断（顺序）栈是否填满
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue SStackIsFull(SSType* pStack);



/**
 （顺序）栈清空
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue SStackClear(SSType* pStack);



/**
 （顺序）栈释放
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue SStackFree(SSType* pStack);



/**
 入（顺序）栈
 
 @param pStack 指向栈的指针变量
 @param inData 入栈数据
 @return 参见‘RetValue’
 */
RetValue SStackPush(SSType* pStack, NodeData inData);




/**
 出（顺序）栈
 
 @param pStack 指向栈的指针变量
 @param outData 出栈数据
 @return 参见‘RetValue’
 */
RetValue SStackPop(SSType* pStack, NodeData* outData);



/**
 读取（顺序）栈顶结点数据
 
 @param pStack 指向栈的指针变量
 @param peekData 栈顶数据
 @return 参见‘RetValue’
 */
RetValue SStackPeek(SSType* pStack, NodeData* peekData);



/**
 显示（顺序）栈所有结点数据
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue SStackShowAll(SSType* pStack);

#endif /* SequentialStack_h */
