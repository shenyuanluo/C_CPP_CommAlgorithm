//
//  SequentialList.h
//  SequentialList
//
//  Created by shenyuanluo on 2017/11/6.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef SequentialList_h
#define SequentialList_h

#include <stdio.h>
#include <string.h>


/** 顺序表最大长度 */
#define MAX_LEN 100


/** 顺序表操作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetSuccess          = 0,            // 操作成功
} RetValue;


/** 顺序表节点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


/** 顺序表结构 */
typedef struct {
    NodeData listData[MAX_LEN];         // 保存顺序表的结构数组
    unsigned int listLen;               // 顺序表已有节点的数量
}SLType;


/**
 初始化顺序表
 
 @param slList 顺序表
 @return 参见 ‘RetValue’
 */
RetValue SLInit(SLType* slList);


/**
 表尾追加节点数据
 
 @param slList 顺序表
 @param nData 插入的节点数据
 @return 参见 ‘RetValue’
 */
RetValue SLAdd(SLType* slList, NodeData nData);


/**
 获取顺序表长度
 
 @param slList 顺序表
 @return 顺序表长度
 */
unsigned int SLlength(SLType* slList);


/**
 插入节点数据
 
 @param slList 顺序表
 @param index 插入的下标
 @param nData 插入的节点数据
 @return 参见 ‘RetValue’
 */
RetValue SLInsert(SLType* slList, int index, NodeData nData);


/**
 删除节点数据
 
 @param slList 顺序表
 @param index 删除的下标
 @return 参见 ‘RetValue’
 */
RetValue SLDelete(SLType* slList, int index);


/**
 根据节点序号查找节点数据
 
 @param slList 顺序表
 @param index 查找的下标
 @return 查找到的数据，否则返回 NULL
 */
NodeData* SLFindByIndex(SLType* slList, int index);


/**
 根据关键字查找节点数据
 
 @param slList 顺序表
 @param key 关键字
 @return 查找到的节点下标，否则返回 RetError
 */
int SLFindByKey(SLType* slList, char* key);


/**
 显示所有节点数据
 
 @param slList 顺序表
 @return 参见 ‘RetValue’
 */
RetValue SLShowAll(SLType* slList);


#endif /* SequentialList_h */
