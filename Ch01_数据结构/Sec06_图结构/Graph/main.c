//
//  main.c
//  Graph
//
//  Created by shenyuanluo on 2017/11/12.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "Graph.h"

int main()
{
    GMType graphMatrix;                     // 定义保存邻接表结构的图
    
    printf("输入生成图的类型：0.无向图；1.有向图\n");
    fflush(stdin);
    scanf("%d", &(graphMatrix.type));
    
    printf("输入图的顶点数量！\n");
    fflush(stdin);
    scanf("%d", &(graphMatrix.vertexNum));
    
    printf("输入图的边数量！\n");
    fflush(stdin);
    scanf("%d", &(graphMatrix.edgeNum));
    
    // 清空图
    GraphClear(&graphMatrix);
    
    // 创建图
    GraphCreate(&graphMatrix);
    
    printf("该图结构的邻接矩阵数据如下：\n");
    // 显示图数据
    GraphShowAll(&graphMatrix);
    
    // 深度优先遍历图结构
    GraphDepthFirstSearch(&graphMatrix);
    
    // 广度优先遍历图结构
    GraphBreadthFirstSearch(&graphMatrix);
    
    return 0;
}
