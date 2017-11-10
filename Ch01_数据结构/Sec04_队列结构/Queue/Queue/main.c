//
//  main.c
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "SequentialQueue.h"
#include "LinkedQueue.h"


#pragma mark -- （顺序）队列测试
void test1()
{
    // 测试
    SQType* pQueue;
    NodeData nData, peekData;
    
    printf("（顺序）队列操作演示开始。。。\n");
    
    // 初始化队列
    pQueue = SQueueInit();
    if (NULL == pQueue)
    {
        printf("（顺序）队列初始化失败！\n");
        
        return;
    }
    
    do
    {
        printf("\n请输入需要添加的结点：学号 姓名 年龄\n");
        
        // 清空输入缓冲区
        fflush(stdin);
        
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        
        if (nData.age)       // 若年龄不为 0
        {
            if (RetError == SQueueIn(pQueue, nData))
            {
                break;      // 添加失败，退出循环
            }
        }
        else
        {
            break;          // 若年龄为 0，条件不符合，退出循环
        }
    } while (1);
    
    printf("\n（顺序）队列中已有的结点为：\n");
    
    SQueueShowAll(pQueue);
    
    printf("出（顺序）队列操作。。。\n");
    
    if (RetSuccess == SQueueOut(pQueue, &nData))
    {
        printf("出（顺序）队列结点是：\nkey = %-15s name = %-20s age = %d\n", nData.key, nData.name, nData.age);
    }
    
    printf("\n（顺序）队列中已有的结点为：\n");
    
    SQueueShowAll(pQueue);
    
    printf("\n查看（顺序）队列顶结点。。。\n");
    
    if (RetSuccess == SQueuePeek(pQueue, &peekData))
    {
        printf("现在（顺序）队列顶结点是：\nkey = %-15s name = %-20s age = %d\n", peekData.key, peekData.name, peekData.age);
    }
    
    printf("\n（顺序）队列中已有的结点为：\n");
    
    SQueueShowAll(pQueue);
    
    printf("\n");
}


#pragma mark -- （链式）队列测试
void test2()
{
    // 测试
    Head* pHead;
    NodeData nData, peekData;
    
    printf("(链式)队列操作演示开始。。。\n");
    
    // 初始化队列
    pHead = LQueueInit();
    if (NULL == pHead)
    {
        printf("(链式)队列初始化失败！\n");
        
        return;
    }
    
    do
    {
        printf("\n请输入需要添加的结点：学号 姓名 年龄\n");
        
        // 清空输入缓冲区
        fflush(stdin);
        
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        
        if (nData.age)       // 若年龄不为 0
        {
            if (RetError == LQueueIn(pHead, nData))
            {
                break;      // 添加失败，退出循环
            }
        }
        else
        {
            break;          // 若年龄为 0，条件不符合，退出循环
        }
    } while (1);
    
    printf("\n队列中已有的结点为：\n");
    
    LQueueShowAll(pHead);
    
    printf("（链式）出队列操作。。。\n");
    
    if (RetSuccess == LQueueOut(pHead, &nData))
    {
        printf("出（链式）队列结点是：\nkey = %-15s name = %-20s age = %d\n", nData.key, nData.name, nData.age);
    }
    
    printf("\n（链式）队列中已有的结点为：\n");
    
    LQueueShowAll(pHead);
    
    printf("\n查看（链式）队头结点。。。\n");
    
    if (RetSuccess == LQueuePeek(pHead, &peekData))
    {
        printf("现在（链式）队头结点是：\nkey = %-15s name = %-20s age = %d\n", peekData.key, peekData.name, peekData.age);
    }
    
    printf("\n（链式）队列中已有的结点为：\n");
    
    LQueueShowAll(pHead);
    
    printf("\n");
}



int main()
{
    test2();
    
    return 0;
}
