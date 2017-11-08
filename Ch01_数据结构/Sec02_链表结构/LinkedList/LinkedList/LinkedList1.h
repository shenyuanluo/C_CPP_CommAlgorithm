//
//  LinkedList1.h
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedList1_h
#define LinkedList1_h

#include "LinkedHeader.h"


/**
 链表表尾添加结点数据

 @param head 链表头指针
 @param data 结点数据
 @return 链表头指针
 */
LLType* LLAddEnd_1(LLType* head, NodeData data);


/**
 链表表头添加结点数据

 @param head 链表头指针
 @param data 结点数据
 @return 链表头指针
 */
LLType* LLAddHead_1(LLType* head, NodeData data);


/**
 根据关键字查找结点

 @param head 链表头指针
 @param key 关键字
 @return 链表头指针
 */
LLType* LLFindByKey_1(LLType* head, char* key);


/**
 在关键字结点后插入结点数据

 @param head 链表头指针
 @param key 插入位置结点的关键字
 @param data 新结点数据
 @return 链表头指针
 */
LLType* LLInsert_1(LLType* head, char* key, NodeData data);


/**
 根据关键字删除结点

 @param head 链表头指针
 @param key 将要删除的结点的关键字
 @return 参见 ‘RetValue’
 */
RetValue LLDelete_1(LLType* head, char* key);


/**
 计算链表长度

 @param head 链表头指针
 @return 链表长度
 */
unsigned int LLLength_1(LLType* head);


/**
 显示所有结点数据

 @param head 链表头指针
 */
void LLShowAll_1(LLType* head);

#endif /* LinkedList1_h */
