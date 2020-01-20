/********************************************************************************************

## 1 股票利润最大

### 题目描述

#### 给定一个数组，包含一段时间的股票价格，需要算出可得到的最大利润。
####    但只能买一次，卖一次，遵守“先买后卖”原则。


********************************************************************************************/

/**
 * 方法一、首先将该数组由价格变换了，价格变化的数组，即数组由[N1, N2 ..., Nn-1, Nn],更换为[N2-N1, ..., Nn - Nn-1],所以该问题变更为寻找最大非空子数组
 *          即寻找某一段最大子数组的最大值，
 * 
 * 
*/
#include <iostream>

using namespace std;

int max_profit_stock(int *array);

int main()
{
    int stock_price[256] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    int stock_price_rate[256];
    for (int i = 1; i < 17; i++)
    {
        stock_price_rate[i - 1] = stock_price[i] - stock_price[i - 1];
        cout << stock_price_rate[i - 1] << " ";
    }
    cout << endl;
    int headptr = 0;
    int tailptr = 0;
    int buy_day = 0;
    int sell_day = 0;
    int max = 0;
    int current_max = 0;
    while (tailptr < 16)
    {
        current_max += stock_price_rate[tailptr];
        if (current_max > max)
        {
            max = current_max;
            buy_day = headptr;
            sell_day = tailptr;
        }
        if (current_max < 0)
        {
            current_max = 0;
            headptr = tailptr + 1;
        }
        tailptr++;
    }
    cout << "we should buy from day:" << buy_day << " sell from day:" << sell_day + 1 << endl;
    cout << "max profit is " << max << endl;
    return 0;
}