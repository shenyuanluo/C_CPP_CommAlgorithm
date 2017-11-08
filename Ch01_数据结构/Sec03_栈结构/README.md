# 栈结构
> 栈（Stack）是从数据的运算来分类的，按照 `后进先出（Last In First Out，LIFO）` 的原则处理节点数据的；在终端处理特别是重要数据的现场保护有着重要意义。而从数据的逻辑结构来看，栈结构其实就是一种线性结构。栈结构包括两类：

![顺序表的存储](SequentialStack.png)

## 栈结构包括两类
1. 顺序栈结构
2. 链式栈结构

## (顺序)栈操作实例代码

### 数据准备
#### 定义栈结构
``` C
/** 栈的最大长度 */
#define MAX_LEN 100


/** 链表操作返回值 */
typedef enum {
    Ret_Error           = -1,           // 操作出错
    Ret_NO              = 0,            // 操作失败
    Ret_YES             = 1,            // 操作成功
}RetValue;


/** 栈结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


/** (顺序)栈结构 */
typedef struct {
    NodeData stackData[MAX_LEN];        // 数据元素
    int stackTop;                       // 栈顶位置
}SSType;
```

#### 栈初始化
``` C
SSType* StackInit()
{
    SSType *pStack;
    if (!(pStack = (SSType *)malloc(sizeof(SSType))))
    {
        printf("无法分配栈内存，栈初始化失败！\n");
        return NULL;
    }
    pStack->stackTop = 0;
    return pStack;
}
```

#### 栈为空判断
``` C
RetValue StackIsEmpty(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行为空判断！\n");
        return Ret_Error;
    }
    
    if (0 == pStack->stackTop)
    {
        return Ret_YES;
    }
    else
    {
        return Ret_NO;
    }
}
```

#### 栈填满判断
``` C
RetValue StackIsFull(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行填满判断！\n");
        return Ret_Error;
    }
    
    if (MAX_LEN == pStack->stackTop)
    {
        return Ret_YES;
    }
    else
    {
        return Ret_NO;
    }
}
```

#### 栈清空
``` C
RetValue StackClear(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行栈清空！\n");
        return Ret_Error;
    }
    
    pStack->stackTop = 0;
    return Ret_YES;
}
```

#### 栈释放
``` C
RetValue StackFree(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法进行栈释放！\n");
        return Ret_Error;
    }
    
    free(pStack);
    return Ret_YES;
}
```

#### 入栈
``` C
RetValue StackPush(SSType* pStack, NodeData nData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法入栈！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsFull(pStack))
    {
        printf("栈已满，无法入栈！\n");
        return Ret_Error;
    }
    
    pStack->stackData[pStack->stackTop] = nData;
    pStack->stackTop++;
    
    return Ret_YES;
}
```

#### 出栈
``` C
RetValue StackPop(SSType* pStack, NodeData* nData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法出栈！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，无法出栈！\n");
        return Ret_Error;
    }
    
    pStack->stackTop--;
    *nData = pStack->stackData[pStack->stackTop];
    
    return Ret_YES;
}
```

#### 读取栈顶节点数据
``` C
RetValue StackPeek(SSType* pStack, NodeData* peekData)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法读取栈顶数据！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，栈顶数据不存在！\n");
        return Ret_Error;
    }
    
    *peekData = pStack->stackData[pStack->stackTop - 1];
    
    return Ret_YES;
}
```

#### 显示栈所有数据
``` C
RetValue StackShowAll(SSType* pStack)
{
    if (NULL == pStack)
    {
        printf("栈指针不存在，无法显示栈所有数据！\n");
        return Ret_Error;
    }
    if (Ret_YES == StackIsEmpty(pStack))
    {
        printf("栈为空，栈数据不存在！\n");
        return Ret_Error;
    }
    
    for (int i = 0; i < pStack->stackTop; i++)
    {
        printf("key = %-15s name = %-20s age = %d\n", pStack->stackData[i].key, pStack->stackData[i].name, pStack->stackData[i].age);
    }
    return Ret_YES;
}
```