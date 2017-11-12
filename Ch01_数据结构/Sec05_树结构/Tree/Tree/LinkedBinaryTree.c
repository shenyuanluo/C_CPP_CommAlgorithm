//
//  LinkedBinaryTree.c
//  Tree
//
//  Created by shenyuanluo on 2017/11/11.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#include "LinkedBinaryTree.h"


#pragma mark --  初始化
LBTType* LBTreeInit()
{
    LBTType* root;
    if (!(root = (LBTType*)malloc(sizeof(LBTType))))
    {
        printf("无法分配树根内存，（链式）树初始化失败！\n");
        return NULL;
    }
    printf("请先输入一个根结点数据：学号 姓名 年龄\n");
    fflush(stdin);
    scanf("%s%s%d", root->nodeData.key, root->nodeData.name, &root->nodeData.age);
    root->parent = NULL;
    root->left   = NULL;
    root->right  = NULL;
    
    return root;
}


#pragma mark --  查找结点
LBTType* LBTreeFindByKey(LBTType* root, char* key)
{
    if (NULL == root)
    {
        return NULL;
    }
    LBTType* findNode = NULL;
    if (0 == strcmp(root->nodeData.key, key))
    {
        return root;
    }
    else
    {
        findNode = LBTreeFindByKey(root->left, key);    // 向左子树递归查找
        if (NULL != findNode)
        {
            return findNode;
        }
        findNode = LBTreeFindByKey(root->right, key);   // 向右子树递归查找
        if (NULL != findNode)
        {
            return findNode;
        }
        return NULL;    // 结点不存在
    }
}


#pragma mark -- 添加结点
RetValue LBTreeAdd(LBTType* root)
{
    if (NULL == root)
    {
        printf("树根结点指针不存在，无法添加新结点数据！\n");
        return RetError;
    }
    LBTType* newNode = NULL;
    if (!(newNode = (LBTType*)malloc(sizeof(LBTType))))
    {
        printf("无法分配新结点内存，（链式）树添加新结点失败！\n");
        return RetFailure;
    }
    LBTType* parentNode = NULL;
    char findKey[15];
    char menuOption;
    
    printf("请输入结点数据：学号 姓名 年龄\n");
    fflush(stdin);
    scanf("%s%s%d", newNode->nodeData.key, newNode->nodeData.name, &newNode->nodeData.age);
    
    newNode->left  = NULL;
    newNode->right = NULL;
    
    printf("请输入作为该结点的父结点的学号\n");
    fflush(stdin);
    scanf("%s", findKey);
    
    parentNode = LBTreeFindByKey(root, findKey);
    if (NULL == parentNode)
    {
        printf("未找到该父结点，添加新结点失败！\n");
        free(newNode);
        return RetFailure;
    }
    printf("1、添加该结点到左子树\n2、添加该结点到右子树\n0、取消\n");
    do
    {
        fflush(stdin);
        menuOption = getchar();
        menuOption -= '0';
        if (1 == menuOption)        // 添加到左子树
        {
            if (NULL != parentNode->left)
            {
                printf("左子树结点不为空，无法添加！\n");
            }
            else
            {
                parentNode->left = newNode;
                newNode->parent  = parentNode;
            }
        }
        else if (2 == menuOption)   // 添加到右子树
        {
            if (NULL != parentNode->right)
            {
                printf("右子树结点不为空，无法添加！\n");
            }
            else
            {
                parentNode->right = newNode;
                newNode->parent   = parentNode;
            }
        }
        else if (0 == menuOption)   // 取消
        {
            return RetFailure;
        }
    } while (1 != menuOption && 2 != menuOption && 0 != menuOption);
    
    printf("添加子结点成功！\n\n");
    return RetSuccess;
}


#pragma mark -- 获取左子树
LBTType* LBTreeLeft(LBTType* node)
{
    if (NULL == node)
    {
        printf("结点指针不存在，无法获取左子树结点！\n");
        return NULL;
    }
    return node->left;
}


#pragma mark -- 获取右子树
LBTType* LBTreeRight(LBTType* node)
{
    if (NULL == node)
    {
        printf("结点指针不存在，无法获取右子树结点！\n");
        return NULL;
    }
    return node->right;
}


#pragma mark -- 判断树是否为空
RetValue LBTreeIsEmpty(LBTType* root)
{
    if (NULL == root)
    {
        return RetFailure;
    }
    else
    {
        return RetSuccess;
    }
}


#pragma mark -- 计算二叉树深度
unsigned int LBTreeDepth(LBTType* root)
{
    if (NULL == root)       // 空树，深度为 0
    {
        return 0;
    }
    unsigned int leftDepth = LBTreeDepth(root->left);       // 递归计算左子树深度
    unsigned int rightDepth = LBTreeDepth(root->right);     // 递归计算左右树深度
    
    if (leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
}


#pragma mark -- 清空二叉树
RetValue LBTreeClear(LBTType* root)
{
    if (NULL == root)
    {
        return RetSuccess;
    }
    LBTreeClear(root->left);    // 递归清空左子树
    LBTreeClear(root->right);   // 递归清空右子树
    
    free(root);     // 释放根结点
    root = NULL;
    
    return RetSuccess;
}


#pragma mark -- 显示结点数据
void LBTreeNodeData(LBTType* node)
{
    if (NULL == node)
    {
        return;
    }
    
    printf("key = %-15s name = %-20s age = %d\n", node->nodeData.key, node->nodeData.name, node->nodeData.age);
}


#pragma mark -- 按层遍历二叉树
void LBTreeLevelTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot))
{
    if (NULL == root)
    {
        printf("树根结点指针不存在，无法按层遍历二叉树数据！\n");
        return;
    }
    LBTType* tempRoot;
    LBTType* qTree[MAX_LEN];                    // 按层保存树结点循环队列
    unsigned int tail = 0;                      // 队尾（入队列）
    unsigned int head = 0;                      // 队头（出队列）
    
    qTree[tail] = root;                         // 二叉树根结点先入队列
    tail = (tail + 1) % MAX_LEN;
    
    while (head != tail)                        // 循环遍历队列数据
    {
        tempRoot = qTree[head];
        head = (head + 1) % MAX_LEN;
        
        LBTreeNodeData(tempRoot);               // 显示结点数据
        
        if (NULL != tempRoot->left)             // 存在左子树，则把左子树入队列
        {
            qTree[tail] = tempRoot->left;       // 左子树根结点入队列
            tail = (tail + 1) % MAX_LEN;
        }
        
        if (NULL != tempRoot->right)            // 存在右子树，则把右子树入队列
        {
            qTree[tail] = tempRoot->right;       // 右子树根结点入队列
            tail = (tail + 1) % MAX_LEN;
        }
    }
}


#pragma mark -- 先序（先根）遍历二叉树
void LBTreeDLRTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot))
{
    if (NULL == root)
    {
        return;
    }
    LBTreeNodeData(root);                               // 显示结点数据
    LBTreeDLRTraversal(root->left, LBTreeNodeData);     // 递归先序遍历左子树
    LBTreeDLRTraversal(root->right, LBTreeNodeData);    // 递归先序遍历右子树
}


#pragma mark -- 中序（中根）遍历二叉树
void LBTreeLDRTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot))
{
    if (NULL == root)
    {
        return;
    }
    
    LBTreeLDRTraversal(root->left, LBTreeNodeData);     // 递归中序遍历左子树
    LBTreeNodeData(root);                               // 显示结点数据
    LBTreeLDRTraversal(root->right, LBTreeNodeData);    // 递归中序遍历右子树
}


#pragma mark -- 后序（后根）遍历二叉树
void LBTreeLRDTraversal(LBTType* root, void (*LBTreeNodeData)(LBTType* nRoot))
{
    if (NULL == root)
    {
        return;
    }
    
    LBTreeLRDTraversal(root->left, LBTreeNodeData);     // 递归后序遍历左子树
    LBTreeLRDTraversal(root->right, LBTreeNodeData);    // 递归后序遍历右子树
    LBTreeNodeData(root);                               // 显示结点数据
}



