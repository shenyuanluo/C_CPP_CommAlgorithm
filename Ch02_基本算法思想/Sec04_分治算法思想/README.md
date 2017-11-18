# 分治算法思想
> 分治算法（Divide and Conquer）是一种化繁为简的算法思想；其基本思想就是将一个计算复杂的问题分为规模较小，计算简单的小问题求解，然后综合各个小问题，得到最终问题的答案。

## 执行过程
1. 对于一个规模为 **N** 的问题，若该问题可以容易地解决（比如说规模 **N** 较小），则直接解决；否则执行下面的步骤。
2. 将该问题分解为 **M** 个规模较小的子问题，这些子问题相互独立，并且与原问题形式相同。
3. 递归地解子问题。
4. 然后，将各个子问题的解合并得到原问题的解。

**注意：**使用分治算法需要待求解问题能够化简为若干个小规模的相同问题，通过逐步划分，达到一个易于求解的阶段而直接进行求解；然后，程序中可以使用递归算法来进行求解。

# 示例
## 假币问题
> **题意：**一个袋子里有 **N** 个硬币，其中有一枚是假币，并且假币和真币外观一模一样，肉眼无法区分；目前只知道假币比真币重量轻一点；问，如何找出假币？

### 解析：
1. 将所有的硬币**等分**成两份，放在天平的两边。这样就将区分 **N** 个硬币的问题，简化为区分两堆硬币的问题。
2. 由题意可知，天平较轻的一侧必定包含有假币在其中。
3. 再将较轻的一侧中的硬币**等分**成两份，重复上述步骤。
4. 直到剩下	`2`枚硬币，可用天平直接找出假硬币。

### 示例代码
``` C
#pragma mark --  求假硬币的编号
unsigned int FalseCoin(unsigned int coinArr[], unsigned int lowNo, unsigned int hightNo)
{
    unsigned int falseNo   = 0;
    unsigned int sumLeft   = 0;
    unsigned int sumCenter = 0;
    unsigned int sumRight  = 0;
    
    if (lowNo + 1 == hightNo)                           // 最后两个硬币
    {
        if (coinArr[lowNo] < coinArr[hightNo])
        {
            falseNo = lowNo + 1;
        }
        else
        {
            falseNo = hightNo + 1;
        }
        return falseNo;
    }
    else if (0 == (hightNo - lowNo + 1) % 2)            // 有偶数个硬币
    {
        int centerNo = lowNo + ((hightNo - lowNo) / 2);
        for (int i = lowNo; i <= centerNo; i++)         // 计算前半部分硬币重量
        {
            sumLeft += coinArr[i];
        }
        
        for (int j = centerNo + 1; j <= hightNo; j++)   // 计算后半部分硬币重量
        {
            sumRight += coinArr[j];
        }
        
        if (sumLeft < sumRight)
        {
            falseNo = FalseCoin(coinArr, lowNo, centerNo);
        }
        else if (sumLeft > sumRight)
        {
            falseNo = FalseCoin(coinArr, centerNo + 1, hightNo);
        }
        else
        {
            printf("计算出错！\n");
        }
        return falseNo;
    }
    else                                                // 有奇数个硬币
    {
        int centerNo = lowNo + ((hightNo - lowNo) / 2);
        for (int i = lowNo; i <= centerNo - 1; i++)     // 计算前半部分硬币的重量
        {
            sumLeft += coinArr[i];
        }
        
        for (int j = centerNo + 1; j <= hightNo; j++)   // 计算后半部分硬币的重量
        {
            sumRight += coinArr[j];
        }
        
        sumCenter = coinArr[centerNo];                  // 中间那枚硬币的重量
        
        if (sumLeft < sumRight)
        {
            falseNo = FalseCoin(coinArr, lowNo, centerNo - 1);
        }
        else if (sumLeft > sumRight)
        {
            falseNo = FalseCoin(coinArr, centerNo + 1, hightNo);
        }
        else
        {
            falseNo = centerNo + 1;
        }
        
        return falseNo;
    }
}
```