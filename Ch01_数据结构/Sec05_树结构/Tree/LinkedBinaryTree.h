//
//  LinkedBinaryTree.h
//  Tree
//
//  Created by shenyuanluo on 2017/11/11.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef LinkedBinaryTree_h
#define LinkedBinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeHeader.h"


/** 树的最大结点数 */
#define MAX_LEN 100


typedef struct LinkedBinaryTree{
    NodeData nodeData;                  // 保存结点数据
    struct LinkedBinaryTree* parent;    // 保存父结点指针
    struct LinkedBinaryTree* left;      // 保存左子树结点指针
    struct LinkedBinaryTree* right;     // 保存右子树结点指针
}LBTType;


/**
 初始化

 @return 指向二叉树根结点的指针
 */
LBTType* LBTreeInit();


/**
 查找结点

 @param root 指向二叉树根结点的指针
 @param key 要查找结点的关键字
 @return 指向符合条件的结点指针
 */
LBTType* LBTreeFindByKey(LBTType* root, char* key);


/**
 添加结点

 @param root 指向二叉树根结点的指针
 @return 参见‘RetValue’
 */
RetValue LBTreeAdd(LBTType* root);


/**
 获取左子树

 @param node 指向子树根结点指针
 @return 指向左子树结点指针
 */
LBTType* LBTreeLeft(LBTType* node);


/**
 获取右子树
 
 @param node 指向子树根结点指针
 @return 指向右子树结点指针
 */
LBTType* LBTreeRight(LBTType* node);


/**
 判断树是否为空

 @param root 指向二叉树根结点的指针
 @return 参见‘RetValue’
 */
RetValue LBTreeIsEmpty(LBTType* root);


/**
 计算二叉树深度

 @param root 指向二叉树根结点的指针
 @return 二叉树深度值
 */
unsigned int LBTreeDepth(LBTType* root);


/**
 清空二叉树

 @param root 指向二叉树根结点的指针
 @return 参见‘RetValue’
 */
RetValue LBTreeClear(LBTType* root);


/**
 显示结点数据

 @param node 指向结点指针
 */
void LBTreeNodeData(LBTType* node);


/**
 按层遍历二叉树

 @param root 指向二叉树根结点的指针
 @param LBTreeNodeData 显示结点数据函数指针
 */
void LBTreeLevelTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot));


/**
 先序（先根）遍历二叉树

 @param root 指向二叉树根结点的指针
 @param LBTreeNodeData 显示结点数据函数指针
 */
void LBTreeDLRTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot));


/**
 中序（中根）遍历二叉树
 
 @param root 指向二叉树根结点的指针
 @param LBTreeNodeData 显示结点数据函数指针
 */
void LBTreeLDRTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot));


/**
 后序（后根）遍历二叉树
 
 @param root 指向二叉树根结点的指针
 @param LBTreeNodeData 显示结点数据函数指针
 */
void LBTreeLRDTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot));

#endif /* LinkedBinaryTree_h */
