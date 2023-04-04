//
//  main.c
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "LinkedList1.h"
#include "LinkedList2.h"
#include <sys/time.h>
#include <unistd.h>


#define COUNT 1


void test1()
{
    LLType* findNode, *head = NULL;
    NodeData nData;
    char deleteKey[10], findKey[10];
    
    printf("链表操作演示开始。。。\n");
    
    do
    {
        printf("\n请输入需要添加的节点：学号 姓名 年龄\n");
        fflush(stdin);
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        if (nData.age)
        {
            head = LLAddEnd_1(head, nData);
        }
        else
        {
            break;  // 若年龄为 0，条件不符合，退出循环
        }
        
    } while (1);
    
    printf("\n链表中已有的节点为：\n");
    
    LLShowAll_1(head);
    
    printf("\n演示查找节点， 输入查找节点的关键字！\n");
    // 清空输入缓冲区
    fflush(stdin);
    scanf("%s", findKey);
    // 查找节点
    findNode = LLFindByKey_1(head, findKey);
    if (NULL == findNode)
    {
        printf("在链表中不存在关键字为：%s 的节点\n", findKey);
    }
    else
    {
        nData = findNode->nodeData;
        printf("关键字为：%s 的节点是：\nkey = %-15s name = %-20s age = %d\n", findKey, nData.key, nData.name, nData.age);
    }
    
    printf("\n演示插入节点， 输入插入位置的关键字！\n");
    scanf("%s", findKey);
    
    // 插入节点
    printf("\n请输入需要插入的节点：学号 姓名 年龄\n");
    fflush(stdin);
    scanf("%s%s%d", nData.key, nData.name, &nData.age);
    LLInsert_1(head, findKey, nData);
    
    printf("\n插入节点后链表中已有的节点为：\n");
    
    LLShowAll_1(head);
    
    printf("\n演示删除节点， 输入删除节点的关键字！\n");
    fflush(stdin);
    scanf("%s", deleteKey);
    // 删除节点
    LLDelete_1(head, deleteKey);
    printf("\n删除节点后链表中已有的节点为：\n");
    
    LLShowAll_1(head);
}


void test2()
{
    LLType* findNode;
    Head* head = NULL;
    NodeData nData;
    char deleteKey[10], findKey[10];
    
    printf("链表操作演示开始。。。\n");
    
    do
    {
        printf("\n请输入需要添加的节点：学号 姓名 年龄\n");
        fflush(stdin);
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        if (nData.age)
        {
            head = LLAddEnd_2(head, nData);
        }
        else
        {
            break;  // 若年龄为 0，条件不符合，退出循环
        }
        
    } while (1);
    
    printf("\n链表中已有的节点为：\n");
    
    LLShowAll_2(head);
    
    printf("\n演示查找节点， 输入查找节点的关键字！\n");
    // 清空输入缓冲区
    fflush(stdin);
    scanf("%s", findKey);
    // 查找节点
    findNode = LLFindByKey_2(head, findKey);
    if (NULL == findNode)
    {
        printf("在链表中不存在关键字为：%s 的节点\n", findKey);
    }
    else
    {
        nData = findNode->nodeData;
        printf("关键字为：%s 的节点是：\nkey = %-15s name = %-20s age = %d\n", findKey, nData.key, nData.name, nData.age);
    }
    
    printf("\n演示插入节点， 输入插入位置的关键字！\n");
    scanf("%s", findKey);
    
    // 插入节点
    printf("\n请输入需要插入的节点：学号 姓名 年龄\n");
    fflush(stdin);
    scanf("%s%s%d", nData.key, nData.name, &nData.age);
    LLInsert_2(head, findKey, nData);
    
    printf("\n插入节点后链表中已有的节点为：\n");
    
    LLShowAll_2(head);
    
    printf("\n演示删除节点， 输入删除节点的关键字！\n");
    fflush(stdin);
    scanf("%s", deleteKey);
    // 删除节点
    LLDelete_2(head, deleteKey);
    printf("\n删除节点后链表中已有的节点为：\n");
    
    LLShowAll_2(head);
}


long long getCurTimeOfUsec()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    
    long long curUsec = tv.tv_sec * 1000000 + tv.tv_usec;
    
    return curUsec;
}


void test3()
{
    long long start = getCurTimeOfUsec();
    
    LLType* head = NULL;
    NodeData data;
    for (int i = 0; i < COUNT; i++)
    {
        strcpy(data.key, "1001");
        strcpy(data.name, "张三");
        data.age = i;
        
        head = LLAddEnd_1(head, data);
    }
    
    long long end = getCurTimeOfUsec();
    printf("方法1总花费时间：%lld\n", end - start);
    
//    LLShowAll_1(head);
}


void test4()
{
    long long start = getCurTimeOfUsec();
    
    Head* head = NULL;
    NodeData data;
    for (int i = 0; i < COUNT; i++)
    {
        strcpy(data.key, "1002");
        strcpy(data.name, "李四");
        data.age = i;
        
        head = LLAddEnd_2(head, data);
    }
    
    long long end = getCurTimeOfUsec();
    printf("方法2总花费时间：%lld\n", end - start);
    
//    LLShowAll_2(head);
}


int main()
{

    test3();
    
    return 0;
}
