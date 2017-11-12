//
//  main.c
//  Tree
//
//  Created by shenyuanluo on 2017/11/11.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include <stdio.h>
#include "LinkedBinaryTree.h"

int main()
{
    LBTType* root;                      // 指向二叉树根结点的指针
    char menuOption;
    void (*LBTreeNodeDataP)();          // 指向函数的指针
    LBTreeNodeDataP = LBTreeNodeData;   // 指向具体操作的函数
    
    // 初始化二叉树
    root = LBTreeInit();
    
    // 添加结点
    do
    {
        printf("请选择菜单添加二叉树的结点！\n");
        printf("0. 退出\n");              // 显示菜单
        printf("1. 添加二叉树结点\n");
        
        fflush(stdin);
        menuOption = getchar();
        
        switch (menuOption)
        {
            case '0':
                break;
                
            case '1':                   // 添加结点
                LBTreeAdd(root);
                
                break;
                
            default:
                break;
        }
    } while ('0' != menuOption);
    
    // 遍历
    do
    {
        printf("请选择菜单遍历二叉树！\n");
        printf("0. 退出\n");
        printf("1. 按层遍历\n");
        printf("2. 先序遍历\n");
        printf("3. 中序遍历\n");
        printf("4. 后序遍历\n");
        
        fflush(stdin);
        menuOption = getchar();
        switch (menuOption)
        {
            case '0':
                break;
                
            case '1':                   // 按层遍历
                printf("\n按层遍历的结果：\n");
                LBTreeLevelTraversal(root, LBTreeNodeDataP);
                printf("\n");
                break;
                
            case '2':                   // 先序遍历
                printf("\n先序遍历的结果：\n");
                LBTreeDLRTraversal(root, LBTreeNodeDataP);
                printf("\n");
                break;
                
            case '3':                   // 中序遍历
                printf("\n中序遍历的结果：\n");
                LBTreeLDRTraversal(root, LBTreeNodeDataP);
                printf("\n");
                break;
                
            case '4':                   // 后序遍历
                printf("\n后续遍历的结果：\n");
                LBTreeLRDTraversal(root, LBTreeNodeDataP);
                printf("\n");
                break;
                
            default:
                break;
        }
        
    } while ('0' != menuOption);
    
    // 树深度
    printf("\n二叉树的深度为：%u\n", LBTreeDepth(root));
    
    // 清空树
    LBTreeClear(root);
    
    return 0;
}
