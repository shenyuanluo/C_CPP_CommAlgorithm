# 穷举算法思想
> 穷举算法（Exhaustive Attack method）是最简单的一种算法，其依赖于计算机的强大计算能力来穷尽每一种可能的情况，从而达到求解问题的目的。其执行步骤如下：

1. 对于每一中可能的情况，计算其结果。
2. 判断结果是否满足要求，如果不满足则执行第 1. 步来搜索下一个可能的情况；如果满足要求，则表示寻找到一个正确的答案。

# 示例
## 鸡兔同笼问题
**"鸡兔同笼"**问题最早记载于 1500 年前的《孙子算经》，其原文如下：
> 今有鸡兔同笼，上有三十五头，下有九十四足，问鸡兔各几何？

**题意：**在一个笼子里关有若干只鸡和若干只兔，从上面数共有 35 个头，从下面数共有 94 只脚。问笼子里鸡和兔的数量各是多少？

### 示例代码
``` C
/** 函数返回值 */
typedef enum {
    RetFailure          = 0,            // 失败
    RetSuccess          = 1,            // 成功
}RetValue;


#pragma mark -- 鸡兔同笼求值
RetValue ExhaustiveAttack(unsigned int headNum, unsigned int footNum, unsigned int* chicken, unsigned int* rabbit)
{
    if (0 == headNum || 0 == footNum)
    {
        return RetFailure;
    }
    for (unsigned int chNum = 0; chNum <= headNum; chNum++)
    {
        unsigned int raNum = headNum - chNum;
        
        if (footNum == chNum * 2 + raNum * 4)
        {
            *chicken = chNum;
            *rabbit  = raNum;
            return RetSuccess;
        }
    }

    return RetFailure;
}
```