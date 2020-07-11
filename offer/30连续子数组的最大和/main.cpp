/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 08 Jul 2020 12:27:25 AM CST
 ************************************************************************/
// 题目描述:
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学.
// 今天测试组开完会后, 他又发话了: 在古老的一维模式识别中,
// 常常需要计算连续子向量的最大和, 当向量全为正数的时候, 问题很好解决.
// 但是, 如果向量中包含负数, 是否应该包含某个负数, 并期望旁边的正数会弥补它呢?
// 例如: {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止).
// 给一个数组, 返回它的最大连续子序列的和, 你会不会被他忽悠住?(子向量的长度至少是1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
// 动态规划法:
// 状态定义: 设DP[i]表示以i结尾的连续子数组的最大和. 所以最终要求DP[i-1]
// 状态转移方程: DP[i] = max(DP[i-1] + array[i], array[i])
// 初始状态DP[0] = array[0]
// 解释: 如果当前元素为整数, 并且DP[i-1]为负数, 那么当然结果就是只选当前元素
class Solution {
    public:
        int FindGreatestSumOfSubArray(vector<int> array) {
            
            int n = array.size();
            if (0 == n) {
                return 0;
            }

            int ans = INT_MIN;
            
            vector<int> DP(n, 0);

            for (int i = 0; i < n; i++) {
                
                if (0 == i) {
                    DP[i] = array[i];
                }
                else {
                    DP[i] = max(DP[i-1]+array[i], array[i]);   
                }

                ans = max(ans, DP[i]);
            }

            return ans;

        }
};

using namespace std;

int main(int argc, char* argv[]) {

    vector<int> array = {6, -3, -2, 7, -15, 1, 2, 2};
    Solution sol;
    int ret = sol.FindGreatestSumOfSubArray(array);
    cout << ret << endl;

    return 0;
}
