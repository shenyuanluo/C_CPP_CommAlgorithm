//
//  LinkedHeader.h
//  LinkedList
//
//  Created by shenyuanluo on 2017/11/7.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedHeader_h
#define LinkedHeader_h


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/** 链表操作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetSuccess          = 0,            // 操作成功
} RetValue;


/** 链表结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


/** 链表结构 */
typedef struct node {
    NodeData nodeData;                  // 保存结点数据
    struct node* nextNode;              // 保存下一结点的地址
}LLType;


#endif /* LinkedHeader_h */
