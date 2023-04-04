//
//  LinkedList1.c
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "LinkedList1.h"


#pragma mark -- 表尾添加结点
LLType* LLAddEnd_1(LLType* head, NodeData data)
{
    LLType* newNode;
    if (!(newNode = (LLType*) malloc(sizeof(LLType))))
    {
        printf("新添加结点内存申请失败，无法在表尾添加结点！\n");
        return NULL;
    }
    newNode->nodeData = data;
    newNode->nextNode = NULL;
    if (NULL == head)
    {
        head = newNode;
        return head;
    }
    LLType* headTemp;
    headTemp = head;
    while (NULL != headTemp->nextNode)
    {
        headTemp = headTemp->nextNode;
    }
    headTemp->nextNode = newNode;
    
    return head;
}


#pragma mark -- 表头添加结点
LLType* LLAddHead_1(LLType* head, NodeData data)
{
    LLType* newNode;
    if (!(newNode = (LLType*)malloc(sizeof(LLType))))
    {
        printf("新添加结点内存申请失败，无法在表头添加结点！\n");
        return NULL;
    }
    newNode->nodeData = data;
    newNode->nextNode = head;
    head = newNode;
    
    return head;
}


#pragma mark -- 根据关键字查找结点
LLType* LLFindByKey_1(LLType* head, char* key)
{
    if (NULL == head)
    {
        printf("链表不存在，无法查找关键字结点！\n");
        return NULL;
    }
    if (NULL == key)
    {
        printf("关键字不存在，无法查找结点！\n");
        return NULL;
    }
    LLType* headTemp = head;
    while (headTemp)
    {
        if (0 == strcmp(headTemp->nodeData.key, key))
        {
            return headTemp;
        }
        headTemp = headTemp->nextNode;
    }
    return NULL;
}


#pragma mark -- 在关键字结点后插入结点数据
LLType* LLInsert_1(LLType* head, char* key, NodeData data)
{
    if (NULL == head)
    {
        printf("链表不存在，无法插入新结点！\n");
        return NULL;
    }
    if (NULL == key)
    {
        printf("关键字不存在，无法插入结点！\n");
        return head;
    }
    LLType* newNode;
    if (!(newNode = (LLType*)malloc(sizeof(LLType))))
    {
        printf("新添加结点内存申请失败，无法添加结点！\n");
        return head;
    }
    newNode->nodeData = data;
    LLType* findNode = LLFindByKey_1(head, key);
    if (findNode)
    {
        newNode->nextNode = findNode->nextNode;
        findNode->nextNode = newNode;
    }
    else
    {
        printf("找不到与关键字匹配的结点，无法插入结点！\n");
        free(newNode);
    }
    return head;
}


#pragma mark -- 根据关键字删除结点
RetValue LLDelete_1(LLType* head, char* key)
{
    if (NULL == head)
    {
        printf("链表不存在，无法删除关键字结点！\n");
        return RetError;
    }
    if (NULL == key)
    {
        printf("关键字不存在，无法删除结点！\n");
        return RetError;
    }
    LLType* findNode = head;
    LLType* headTemp = head;
    while (findNode)
    {
        if (0 == strcmp(findNode->nodeData.key, key))
        {
            headTemp->nextNode = findNode->nextNode;
            findNode->nextNode = NULL;
            free(findNode);
            
            return RetSuccess;
        }
        else
        {
            headTemp = findNode;
            findNode = findNode->nextNode;
        }
    }
    
    return RetError;
}


#pragma mark -- 计算链表长度
unsigned int LLLength_1(LLType* head)
{
    if (NULL == head)
    {
        printf("链表不存在，无法计算链表长度！\n");
        return 0;
    }
    LLType* headTemp = head;
    int length = 0;
    while (headTemp)
    {
        length++;
        headTemp = headTemp->nextNode;
    }
    
    return length;
}


#pragma mark -- 显示所有结点数据
void LLShowAll_1(LLType* head)
{
    if (NULL == head)
    {
        printf("链表不存在，无法显示所有结点！\n");
        return;
    }
    LLType* headTemp = head;
    while (headTemp)
    {
        printf("key = %-15s name = %-20s age = %d\n", headTemp->nodeData.key, headTemp->nodeData.name, headTemp->nodeData.age);
        headTemp = headTemp->nextNode;
    }
}

