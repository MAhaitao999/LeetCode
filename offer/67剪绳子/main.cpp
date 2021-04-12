/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 20 May 2020 10:41:29 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
/**
 * 题目分析：
 * 先举几个例子，可以看出规律来。
 * 4 ： 2*2
 * 5 ： 2*3
 * 6 ： 3*3
 * 7 ： 2*2*3 或者4*3
 * 8 ： 2*3*3
 * 9 ： 3*3*3
 * 10：2*2*3*3 或者4*3*3
 * 11：2*3*3*3
 * 12：3*3*3*3
 * 13：2*2*3*3*3 或者4*3*3*3
 *
 * 下面是分析：
 * 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
 * 当然也可能有4，但是4=2*2，我们就简单些不考虑了。
 * 5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。
 * 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。
 * 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。
 * 由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回就行了。
 *
 * 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。
 */
class Solution {
public:
    int cutRope(int number) {
        if (number == 2) {
            return 1;
        }
        if (number == 3) {
            return 2;
        }
        
        long long x = number / 3;
        long long y = number % 3;
        
        if (y == 0) 
            return pow(3, x);
        else if (y == 1)
            return (long long) pow(3, x-1) * 2 * 2;
        else
            return (long long) pow(3, x) * 2;
    }
};


// 动态规划
class Solution2 {
public:
    int cutRope(int number) {
        if (number < 2)
            return 1;
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;
        
        int *dp = new int[number+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for (int i = 4; i <= number; i++) {
            for (int j = 1; j <= number / 2; j++) {  // 剪刀的位置
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        
        int res = dp[number];
        delete [] dp;
        return res;
    }
};

int main(int argc, char* argv[]) {
    
    Solution2 sol;
    cout << sol.cutRope(49) << endl;
    return 0;

}
