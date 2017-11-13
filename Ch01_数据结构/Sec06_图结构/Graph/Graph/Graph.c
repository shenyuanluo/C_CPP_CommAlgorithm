//
//  Graph.c
//  Graph
//
//  Created by shenyuanluo on 2017/11/13.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "Graph.h"


#pragma mark -- 创建图
void GraphCreate(GMType* gm)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法创建图结构！\n");
        return;
    }
    int i, j, k;
    int weight;                                         // 权值
    char eStartV;                                       // 边的起始顶点
    char eEndV;                                         // 边的结束顶点
    
    printf("请输入图中各顶点信息！\n");
    
    for (int i = 0; i < gm->vertexNum; i++)
    {
        getchar();
        printf("第 %d 个顶点：", i + 1);
        scanf("%c", &(gm->vertex[i]));                  // 保存到各顶点数组元素中
    }
    
    printf("\n输入构成各边的顶点及权值，格式：起始顶点 结束顶点 权值 \n");
    
    for (k = 0; k < gm->edgeNum; k++)                   // 输入各边的值
    {
        getchar();
        printf("第 %d 条边：", k + 1);
        scanf("%c %c %d", &eStartV, &eEndV, &weight);
        
        for (i = 0; eStartV != gm->vertex[i]; i++);     // 在已有顶点中查找边的起始顶点
        
        for (j = 0; eEndV != gm->vertex[j]; j++);       // 在已有顶点中查找边的结束顶点
        
        // 顶点找到
        gm->edgeWeight[i][j] = weight;                  // 在对应位置保存权值，表示有一条边
        if (0 == gm->type)      // 无向图
        {
            gm->edgeWeight[j][i] = weight;              // 在对角位置保存权值
        }
    }
}


#pragma mark -- 清空图
void GraphClear(GMType* gm)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法清空图结构！\n");
        return;
    }
    for (int i = 0; i < gm->vertexNum; i++)
    {
        for (int j = 0; j < gm->vertexNum; j++)
        {
            gm->edgeWeight[i][j] = MAX_VALUE;           // 设置矩阵中各元素的值为 Max Value
        }
    }
}


#pragma mark -- 显示图
void GraphShowAll(GMType* gm)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法显示图结构！\n");
        return;
    }
    for (int i = 0; i < gm->vertexNum; i++)
    {
        printf("\t%c", gm->vertex[i]);                  //  在第1行输出顶点信息
    }
    printf("\n");
    
    for (int j = 0; j < gm->vertexNum; j++)
    {
        printf("%c", gm->vertex[j]);
        
        for (int k = 0; k < gm->vertexNum; k++)
        {
            if (MAX_VALUE == gm->edgeWeight[j][k])
            {
                printf("\tZ");                          // "Z" 表示无穷大
            }
            else
            {
                printf("\t%d", gm->edgeWeight[j][k]);   // 输出边的权值
            }
        }
        printf("\n");
    }
}


#pragma mark -- 深度优先遍历单个顶点的邻接顶点
void GraphDFTOne(GMType* gm, unsigned int index)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法深度优先遍历单个顶点的邻接顶点！\n");
        return;
    }
    gm->isTraverse[index] = TRAVERSE_YES;               // 标记该顶点已处理过
    printf("-->%c", gm->vertex[index]);
    
    // 添加处理结点的操作
    for (int i = 0; i < gm->vertexNum; i++)
    {
        if (MAX_VALUE != gm->edgeWeight[index][i]
            && TRAVERSE_NO == gm->isTraverse[i])
        {
            GraphDFTOne(gm, i);                     // 递归对该顶点的邻接顶点进行遍历
        }
    }
}


#pragma mark -- 深度优先遍历图结构
void GraphDeepFirstTraverse(GMType* gm)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法深度优先遍历图结构！\n");
        return;
    }
    for (int i = 0; i < gm->vertexNum; i++)             // 清除各顶点的遍历标志
    {
        gm->isTraverse[i] = TRAVERSE_NO;
    }
    printf("深度优先遍历图结构结点！\n");
    
    for (int j = 0; j < gm->vertexNum; j++)
    {
        if (TRAVERSE_NO == gm->isTraverse[j])
        {
            GraphDFTOne(gm, j);
        }
    }
    printf("\n");
}


