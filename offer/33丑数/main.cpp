/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sat 11 Jul 2020 08:35:44 PM CST
 ************************************************************************/
// 题目描述:
// 把只包含质因子2、3和5的数称作丑数(Ugly Number).
// 例如6、8都是丑数, 但14不是, 因为它包含质因子7.
// 习惯上我们把1当做是第一个丑数. 求按从小到大的顺序的第N个丑数.

// 丑数的通项公式可以写作: 2^x * 3^y * 5^z
// 思路: 利用3个队列分别存放x2, x3, x5的数. 每次从三个队列的头部取出其中的
// 最小值, 然后分别将这个值再x2, x3, x5存放到三个队列的尾部.
// 初始化:
// q_2 = [1,], q_3 = [1,] q_5 = [1,]
// 第一轮: res = 1(将三个队列的头部1都弹出)
// q_2 = [1x2,], q_3 = [1x3,], q_5 = [1x5]
// 第二轮: res = 2(将q_2队列的头部2弹出)
// q_2 = [2x2,], q_3 = [1x3, 2x3], q_5 = [1x5, 2x5]
// 第三轮: res = 3(将q_3队列的头部3弹出)
// q_2 = [2x2, 3x2], q_3 = [2x3, 3x3], q_5 = [1x5, 2x5, 3x5]
// ......
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        int GetUglyNumber_Solution(int index) {
            queue<int> q_2, q_3, q_5;

            // 初始化, 三个队列中都放入1
            q_2.push(1);
            q_3.push(1);
            q_5.push(1);
            int res = 0;

            for (int i = 0; i < index; i++) {
                // 取三个队列中头部最小的值
                res = min(q_2.front(), min(q_3.front(), q_5.front()));
                
                // 分别将res x2, x3, x5放入三个队列中
                q_2.push(res * 2);
                q_3.push(res * 3);
                q_5.push(res * 5);

                // 弹出三个队列中头部为res的数
                if (q_2.front() == res) {
                    q_2.pop();
                }
                if (q_3.front() == res) {
                    q_3.pop();
                }
                if (q_5.front() == res) {
                    q_5.pop();
                }
            }

            return res;
            
        }
};

int main(int argc, char* argv[]) {

    int index = 100;
    Solution sol;
    int res = sol.GetUglyNumber_Solution(index);

    cout << res << endl;
    return 0;
}
