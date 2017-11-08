//
//  LinkedList2.h
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedList2_h
#define LinkedList2_h

#include "LinkedHeader.h"

/** 链表头 */
typedef struct _head {
    LLType* headNode;               // 保存链表头结点地址
    LLType* tailNode;               // 保存链表尾结点地址
    unsigned int clLength;          // 链表长度
}Head;


/**
 链表表尾添加结点数据
 
 @param head 链表头指针
 @param data 结点数据
 @return 链表头指针
 */
Head* LLAddEnd_2(Head* head, NodeData data);


/**
 链表表头添加结点数据
 
 @param head 链表头指针
 @param data 结点数据
 @return 链表头指针
 */
Head* LLAddHead_2(Head* head, NodeData data);


/**
 根据关键字查找结点
 
 @param head 链表头指针
 @param key 关键字
 @return 链表头指针
 */
LLType* LLFindByKey_2(Head* head, char* key);


/**
 在关键字结点后插入结点数据
 
 @param head 链表头指针
 @param key 插入位置结点的关键字
 @param data 新结点数据
 @return 链表头指针
 */
Head* LLInsert_2(Head* head, char* key, NodeData data);


/**
 根据关键字删除结点
 
 @param head 链表头指针
 @param key 将要删除的结点的关键字
 @return 参见 ‘RetValue’
 */
RetValue LLDelete_2(Head* head, char* key);


/**
 计算链表长度
 
 @param head 链表头指针
 @return 链表长度
 */
unsigned int LLLength_2(Head* head);


/**
 显示所有结点数据
 
 @param head 链表头指针
 */
void LLShowAll_2(Head* head);

#endif /* LinkedList2_h */
