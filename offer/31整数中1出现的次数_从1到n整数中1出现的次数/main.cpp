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

// 方法2:
// 假设n=21067, 分别讨论每个数位上为1的个数. 定义三个变量: 
// cur(当前位上的数字), high(当前位左边), low(当前位右边).
// 例如cur = 0, high = 21, low=67
// 分三种情况讨论cur:
// - 1. cur = 0: 001xx-201xx, xx从00取到99 所以此情况下总共有
// (high)*100
// - 2. cur = 1: 01xxx-11xxx, 21000-21067, 所以此情况下总共有
// high * 1000 + (low + 1)
// - 3. cur > 1, 比如6: 0001x-2101x, x从0取到9, 所以此情况下总
// 共有(high+1)*10
class Solution2 {
    public:
        int NumberOf1Between1AndN_Solution(int n) {
            int count = 0;
            for(int i = 1; i <=n; i*=10) { // i代表位数, 从个位开始
                int high = n / (i * 10);
                int low = n % i;
                int cur = (n % (i * 10)) / i;

                if (0 == cur) {
                    count += high * i;
                }

                else if (1 == cur) {
                    count += high * i + (low + 1);
                }

                else {
                    count += (high + 1) * i;
                }
            
            }

            return count;
        }
};


int main(int argc, char* argv[]) {

    int k = 21067;
    Solution2 sol;
    int res = sol.NumberOf1Between1AndN_Solution(k);
    cout << res << endl;
    return 0;
}
