/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Fri 10 Jul 2020 12:19:05 AM CST
 ************************************************************************/
// 题目描述:
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
// 但是对于后面问题他就没辙了。ACMer希望你们帮帮他, 并把问题更加普遍化,
// 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
#include <iostream>
using namespace std;

// 方法1: 暴力法
// 遍历从1到n的数, 对每一个数进行解析, 每个数的解析时间是log10(n).
// 算法时间复杂度是nlog(n)
class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += countOne(i);
            }
            return sum;
        }

    private:
        int countOne(int n) {
            int count = 0;
            while (n != 0) {
                int a = n%10;
                if (a == 1) {
                    count++;
                }
                n /= 10;
            }
            return count;
        }
};


int main(int argc, char* argv[]) {

    int k = 13;
    Solution sol;
    int res = sol.NumberOf1Between1AndN_Solution(k);
    cout << res << endl;
    return 0;
}
