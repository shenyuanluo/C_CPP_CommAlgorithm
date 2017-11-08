//
//  SequentialList.c
//  SequentialList
//
//  Created by shenyuanluo on 2017/11/6.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "SequentialList.h"


#pragma mark -- 初始化顺序表
RetValue SLInit(SLType* slList)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行初始化操作！\n");
        return RetError;
    }
    
    slList->listLen = 0;
    
    return RetSuccess;
}


#pragma mark -- 获取顺序表长度
unsigned int SLlength(SLType* slList)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行获取顺序表长度操作！\n");
        return 0;
    }
    
    return slList->listLen;
}


#pragma mark -- 表尾追加节点数据
RetValue SLAdd(SLType* slList, NodeData nData)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行追加新节点操作！\n");
        return RetError;
    }
    
    if (MAX_LEN <= slList->listLen)
    {
        printf("顺序表已满，无法追加新节点数据！\n");
        return RetError;
    }
    
    slList->listData[slList->listLen++] = nData;
    
    return RetSuccess;
}


#pragma mark -- 插入节点数据
RetValue SLInsert(SLType* slList, int index, NodeData nData)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行插入新节点操作！\n");
        return RetError;
    }
    
    if (MAX_LEN <= slList->listLen)
    {
        printf("顺序表已满，无法插入新节点数据！\n");
        return RetError;
    }
    
    if (0 > index || slList->listLen <= index)
    {
        printf("插入节点下标错误，无法插入新节点数据！\n");
        return RetError;
    }
    
    for (int i = slList->listLen; i >= index; i--)
    {
        slList->listData[i] = slList->listData[i - 1];
    }
    slList->listData[index] = nData;
    slList->listLen++;
    
    return RetSuccess;
}


#pragma mark -- 删除节点数据
RetValue SLDelete(SLType* slList, int index)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行删除节点操作！\n");
        return RetError;
    }
    
    if (0 == slList->listLen)
    {
        printf("顺序表为空，无法删除节点数据！\n");
        return RetError;
    }
    
    if (0 > index || slList->listLen <= index)
    {
        printf("插入节点下标错误，无法删除节点数据！\n");
        return RetError;
    }
    
    for (int i = index; i < slList->listLen - 1; i++)
    {
        slList->listData[i] = slList->listData[i + 1];
    }
    slList->listLen--;
    
    return RetSuccess;
}


#pragma mark -- 根据节点序号查找节点数据
NodeData* SLFindByIndex(SLType* slList, int index)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行查找节点操作！\n");
        return NULL;
    }
    
    if (0 == slList->listLen)
    {
        printf("顺序表为空，无法查找节点数据！\n");
        return NULL;
    }
    
    if (0 > index || slList->listLen <= index)
    {
        printf("查找节点下标错误，无法查找节点数据！\n");
        return NULL;
    }
    
    return &(slList->listData[index]);
}


#pragma mark -- 根据关键字查找节点序号
int SLFindByKey(SLType* slList, char* key)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行关键字查找节点操作！\n");
        return RetError;
    }
    
    if (0 >= slList->listLen)
    {
        printf("顺序表为空，无法查找关键字节点数据！\n");
        return RetError;
    }
    
    for (int i = 0; i < slList->listLen; i++)
    {
        if (0 == strcmp(key, slList->listData[i].key))
        {
            return i;
        }
    }
    printf("顺序表不存在关键字为：%s 的节点数据！\n", key);
    return RetError;
}


#pragma mark -- 显示所有节点数据
RetValue SLShowAll(SLType* slList)
{
    if (NULL == slList)
    {
        printf("顺序表不存在，无法进行显示所有节点操作！\n");
        return RetError;
    }
    
    if (0 >= slList->listLen)
    {
        printf("顺序表为空，无法显示所有节点数据！\n");
        return RetError;
    }
    
    for (int i = 0; i < slList->listLen; i++)
    {
        // 清空输出缓冲区
        fflush(stdout);
        printf("key = %-15s name = %-20s age = %d\n", slList->listData[i].key, slList->listData[i].name, slList->listData[i].age);
    }
    return RetSuccess;
}
