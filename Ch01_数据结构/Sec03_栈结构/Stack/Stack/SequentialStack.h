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


/** 栈的最大长度 */
#define MAX_LEN 100


/** 链表操作返回值 */
typedef enum {
    Ret_Error           = -1,           // 操作出错
    Ret_NO              = 0,            // 操作失败
    Ret_YES             = 1,            // 操作成功
}RetValue;


/** 栈结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


/** (顺序)栈结构 */
typedef struct {
    NodeData stackData[MAX_LEN];        // 数据元素
    int stackTop;                       // 栈顶位置
}SSType;



/**
 栈初始化
 
 @return 返回指向栈的指针变量
 */
SSType* StackInit();



/**
 判断栈是否为空
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue StackIsEmpty(SSType* pStack);



/**
 判断栈是否填满
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue StackIsFull(SSType* pStack);



/**
 栈清空
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue StackClear(SSType* pStack);



/**
 栈释放
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue StackFree(SSType* pStack);



/**
 入栈
 
 @param pStack 指向栈的指针变量
 @param nData 需要入栈数据
 @return 参见‘RetValue’
 */
RetValue StackPush(SSType* pStack, NodeData nData);




/**
 出栈
 
 @param pStack 指向栈的指针变量
 @param nData 出栈数据
 @return 参见‘RetValue’
 */
RetValue StackPop(SSType* pStack, NodeData* nData);



/**
 读取栈顶节点数据
 
 @param pStack 指向栈的指针变量
 @param peekData 栈顶数据
 @return 参见‘RetValue’
 */
RetValue StackPeek(SSType* pStack, NodeData* peekData);



/**
 显示栈所有节点数据
 
 @param pStack 指向栈的指针变量
 @return 参见‘RetValue’
 */
RetValue StackShowAll(SSType* pStack);

#endif /* SequentialStack_h */
