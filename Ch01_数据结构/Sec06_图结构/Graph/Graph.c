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
    
    for (int j = 0; j < gm->edgeNum; j++)                   // 输入各边的值
    {
        getchar();
        printf("第 %d 条边：", j + 1);
        scanf("%c %c %d", &eStartV, &eEndV, &weight);
        
        int startIndex, endIndex;
        // 在已有顶点中循环查找边的起始顶点
        for (startIndex = 0; startIndex < gm->vertexNum; startIndex++)
        {
            if (eStartV == gm->vertex[startIndex])
            {
                break;
            }
        }
        // 在已有顶点中循环查找边的结束顶点
        for (endIndex = 0; endIndex < gm->vertexNum; endIndex++)
        {
            if (eEndV == gm->vertex[endIndex])
            {
                break;
            }
        }
        if (gm->vertexNum <= startIndex)
        {
            printf("起始顶点不存在，请重新输入！\n");
            j--;
            continue;
        }
        if (gm->vertexNum <= endIndex)
        {
            printf("结束顶点不存在，请重新输入！\n");
            j--;
            continue;
        }
        
        // 顶点找到
        gm->edgeWeight[startIndex][endIndex] = weight;                  // 在对应位置保存权值，表示有一条边
        if (0 == gm->type)      // 无向图
        {
            gm->edgeWeight[endIndex][startIndex] = weight;              // 在对角位置保存权值
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


#pragma mark -- 访问某个顶点的值
void GraphVisitVertex(GMType* gm, unsigned int index)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法访问某个顶点的值！\n");
        return;
    }
    printf("-->%c", gm->vertex[index]);
}


#pragma mark -- 查询关键字-key 对应的顶点下标
unsigned int GraphNodeIndex(GMType* gm, char key)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法查询关键字-key 对应的顶点下标！\n");
        return MAX_VALUE;
    }
    for (int i = 0; i < gm->vertexNum; i++)
    {
        if (key == gm->vertex[i])
        {
            return i;
        }
    }
    return MAX_VALUE;
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
            GraphDFTOne(gm, i);                         // 递归对该顶点的邻接顶点进行遍历
        }
    }
}


#pragma mark --  深度优先遍历(或深度优先搜索：Depth First Search)图结构
void GraphDepthFirstSearch(GMType* gm)
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


#pragma mark -- 广度优先遍历(或广度优先搜索：Breadth First Search)图结构
void GraphBreadthFirstSearch(GMType* gm)
{
    if (NULL == gm)
    {
        printf("图结构指针不存在，无法广度优先遍历图结构！\n");
        return;
    }
    for (int i = 0; i < gm->vertexNum; i++)             // 清除各顶点的遍历标志
    {
        gm->isTraverse[i] = TRAVERSE_NO;
    }
    
    char qGraph[MATRIX_NUM];                            // 图结点循环队列
    unsigned int tail = 0;                              // 队尾（入队列）
    unsigned int head = 0;                              // 队头（出队列）
    
    printf("广度度优先遍历图结构结点！\n");
    
    for (int j = 0; j < gm->vertexNum; j++)
    {
        if (TRAVERSE_NO == gm->isTraverse[j])
        {
            gm->isTraverse[j] = TRAVERSE_YES;           // 标记该顶点已处理过
            GraphVisitVertex(gm, j);
            qGraph[tail++] = gm->vertex[j];             // 已处理的顶入队列
            
            while (head != tail)                        // 循环遍历队列数据
            {
                int outIndex = GraphNodeIndex(gm, qGraph[head++]);  // 查询出队列顶点编号
                
                if (gm->vertexNum <= outIndex)
                {
                    break;
                }
                for(int k = 0; k < gm->vertexNum; k++)              // 寻找出队列的顶点的所有邻接顶点
                {
                    if(MAX_VALUE != gm->edgeWeight[outIndex][k]
                       && TRAVERSE_NO == gm->isTraverse[k])
                    {
                        gm->isTraverse[k] = TRAVERSE_YES;           // 标记该顶点已处理过
                        GraphVisitVertex(gm, k);
                        qGraph[tail++] = gm->vertex[k];             // 已处理的顶入队列
                    }
                }
            }
        }
    }
    printf("\n");
}
