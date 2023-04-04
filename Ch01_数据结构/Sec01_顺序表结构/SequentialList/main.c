//
//  main.c
//  SequentialList
//
//  Created by shenyuanluo on 2017/11/6.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "SequentialList.h"

int main()
{
    // 测试
    int index;
    SLType slList;          // 定义顺序表变量
    NodeData nData;          // 定义节点保存数据类型变量
    NodeData *pData;        // 定义节点保存指针变量
    char key[15];           // 保存关键字
    
    printf("顺序表操作演示开始。。。\n");
    
    printf("\n初始化顺序表！\n");
    
    // 初始化顺序表
    SLInit(&slList);

    printf("\n初始化顺序表完成！\n");
    
    do
    {
        printf("\n请输入需要添加的节点：学号 姓名 年龄\n");
        fflush(stdin);
        scanf("%s%s%d", nData.key, nData.name, &nData.age);
        if (nData.age)
        {
            if (RetError == SLAdd(&slList, nData))
            {
                break;
            }
        }
        else
        {
            break;  // 若年龄为 0，条件不符合，退出循环
        }
        
    } while (1);
    
    printf("\n演示显示节点操作！\n");
    
    // 显示所有节点数据
    SLShowAll(&slList);
    
    printf("\n演示获取顺序表长度操作！\n");
    
    unsigned int listLen = SLlength(&slList);
    printf("顺序表长度：%u\n", listLen);
    
    printf("\n演示插入节点， 输入插入位置的序号！\n");
    scanf("%d", &index);
    
    // 插入节点
    printf("\n请输入需要插入的节点：学号 姓名 年龄\n");
    fflush(stdin);
    scanf("%s%s%d", nData.key, nData.name, &nData.age);
    SLInsert(&slList, index, nData);
    
    SLShowAll(&slList);
    
    
    printf("\n演示查找节点， 输入查找位置的序号！\n");
    
    fflush(stdin);
    scanf("%d", &index);
    
    // 按序号查找节点
    pData = SLFindByIndex(&slList, index);
    if (NULL != pData)
    {
        printf("第 %d 个节点的数据内容：%s  %s  %d", index, pData->key, pData->name, pData->age);
    }
    
    printf("\n演示查找节点， 请输入要查找的关键字！\n");
    fflush(stdin);
    scanf("%s", key);
    
    index = SLFindByKey(&slList, key);
    pData = SLFindByIndex(&slList, index);
    if (NULL != pData)
    {
        printf("第 %d 个节点的数据内容：%s  %s  %d\n", index, pData->key, pData->name, pData->age);
    }
    return 0;
}
