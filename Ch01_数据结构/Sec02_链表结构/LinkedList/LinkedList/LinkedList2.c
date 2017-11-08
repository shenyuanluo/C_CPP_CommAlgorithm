//
//  LinkedList2.c
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "LinkedList2.h"


#pragma mark -- 表尾添加结点
Head* LLAddEnd_2(Head* head, NodeData data)
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
        head = (Head*)malloc(sizeof(Head));
        head->headNode = newNode;
        head->tailNode = newNode;
        head->clLength = 1;
        return head;
    }
    head->tailNode->nextNode = newNode;
    head->tailNode = newNode;
    head->clLength++;
    
    return head;
}


#pragma mark -- 表头添加结点
Head* LLAddHead_2(Head* head, NodeData data)
{
    LLType* newNode;
    if (!(newNode = (LLType*)malloc(sizeof(LLType))))
    {
        printf("新添加结点内存申请失败，无法在表头添加结点！\n");
        return NULL;
    }
    newNode->nodeData = data;
    if (NULL == head)
    {
        newNode->nextNode = NULL;
        head = (Head*)malloc(sizeof(Head));
        head->headNode = newNode;
        head->tailNode = newNode;
        head->clLength = 1;
        return head;
    }
    newNode->nextNode = head->headNode;
    head->headNode = newNode;
    head->clLength++;
    
    return head;
}


#pragma mark -- 根据关键字查找结点
LLType* LLFindByKey_2(Head* head, char* key)
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
    LLType* headTemp = head->headNode;
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


#pragma mark --  在关键字结点后插入结点数据
Head* LLInsert_2(Head* head, char* key, NodeData data)
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
    LLType* findNode = LLFindByKey_2(head, key);
    if (findNode)
    {
        newNode->nextNode = findNode->nextNode;
        findNode->nextNode = newNode;
        head->clLength++;
    }
    else
    {
        printf("找不到与关键字匹配的结点，无法插入结点！\n");
        free(newNode);
    }
    
    return head;
}


#pragma mark -- 根据关键字删除结点
RetValue LLDelete_2(Head* head, char* key)
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
    LLType* findNode = head->headNode;
    LLType* headTemp = head->headNode;
    while (findNode)
    {
        if (0 == strcmp(findNode->nodeData.key, key))
        {
            headTemp->nextNode = findNode->nextNode;
            findNode->nextNode = NULL;
            free(findNode);
            head->clLength--;
            
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
unsigned int LLLength_2(Head* head)
{
    if (NULL == head)
    {
        printf("链表不存在，无法计算链表长度！\n");
        return 0;
    }
    return head->clLength;
}


#pragma mark -- 显示所有结点数据
void LLShowAll_2(Head* head)
{
    if (NULL == head)
    {
        printf("链表不存在，无法显示所有结点！\n");
        return;
    }
    LLType* headTemp = head->headNode;
    while (headTemp)
    {
        printf("key = %-15s name = %-20s age = %d\n", headTemp->nodeData.key, headTemp->nodeData.name, headTemp->nodeData.age);
        headTemp = headTemp->nextNode;
    }
}
