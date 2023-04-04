//
//  Graph.h
//  Graph
//
//  Created by shenyuanluo on 2017/11/13.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** 图的最大顶点数量 */
#define MATRIX_NUM 20

/** 图的权无效值（最大值） */
#define MAX_VALUE 65535

/** 顶点已遍历标志 */
#define TRAVERSE_YES 1

/** 顶点未遍历标志 */
#define TRAVERSE_NO 0


/** 邻接矩阵图结构 */
typedef struct GraphMatrix{
    char vertex[MATRIX_NUM];                // 保存顶点信息（序号或字母）
    int type;                               // 图的类型（0：无向图；1：有向图）
    int vertexNum;                          // 顶点的数量
    int edgeNum;                            // 边的数量
    int edgeWeight[MATRIX_NUM][MATRIX_NUM]; // 保存边的权
    int isTraverse[MATRIX_NUM];             // 遍历标志
}GMType;


/**
 创建图

 @param gm 指向图结构的指针
 */
void GraphCreate(GMType* gm);


/**
 清空图

 @param gm 指向图结构的指针
 */
void GraphClear(GMType* gm);


/**
 访问某个顶点的值

 @param gm 指向图结构的指针
 @param index 顶点的下标
 */
void GraphVisitVertex(GMType* gm, unsigned int index);

/**
 查询关键字-key 对应的顶点下标

 @param gm  指向图结构的指针
 @param key 关键字-key
 @return 顶点的下标
 */
unsigned int GraphNodeIndex(GMType* gm, char key);


/**
 显示图

 @param gm 指向图结构的指针
 */
void GraphShowAll(GMType* gm);


/**
 深度优先遍历单个顶点的邻接顶点

 @param gm 指向图结构的指针
 @param index 第 index 个顶点
 */
void GraphDFTOne(GMType* gm, unsigned int index);


/**
 深度优先遍历(或深度优先搜索：Depth First Search)图结构

 @param gm 指向图结构的指针
 */
void GraphDepthFirstSearch(GMType* gm);


/**
 广度优先遍历(或广度优先搜索：Breadth First Search)图结构
 
 @param gm 指向图结构的指针
 */
void GraphBreadthFirstSearch(GMType* gm);


#endif /* Graph_h */
