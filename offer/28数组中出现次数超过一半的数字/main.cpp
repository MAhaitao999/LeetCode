/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed Jun 24 22:52:04 2020
 ************************************************************************/
// 题目描述:
// 数组中有一个数字出现的次数超过数组长度的一半, 请找出这个数字. 例如输入一个
// 长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}. 由于数字2在数组中出现了5次, 超过
// 数组长度的一半, 因此输出2. 如果不存在则输出0.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 方法一: 哈希法
// 根据题目意思, 虽然可以先遍历一遍数组, 在map中存每个元素出现的次数,
// 然后再遍历一次数组, 找到众数.
// 时间复杂度: O(n), 空间复杂度: O(n)

class Solution {
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers) {
            unordered_map<int, int> mp;
            for (const int val : numbers) {
                ++mp[val];
            }

            for (const int val : numbers) {
                if (mp[val] > numbers.size() / 2) {
                    return val;
                }
            }

            return 0;
        }
};

// 方法二: 排序法
// 可以先将数组排序, 然后可能的众数肯定在数组中间, 然后判断一下.
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)

class Solution2 {
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers) {
            sort(numbers.begin(), numbers.end());
            int cond = numbers[numbers.size() / 2];

            int count = 0;
            for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
                if (*iter == cond) {
                    count++;
                }
            }

            if (count > numbers.size() / 2) {
                return cond;
            }

            else {
                return 0;
            }
        }
};

// 方法三: 候选法(最优解)
// 加入数组中存在众数, 那么众数一定大于数组的长度的一半.
// 思路就是: 如果两个数不相等, 就消去这两个数, 最坏情况下, 
// 每次消去一个众数和非众数, 那么如果存在众数, 最后留下的数肯定就是众数.
// 具体做法:
// 1. 初始化: 候选人cond=-1, 候选cond=-1, 候选人的投票次数cnt=0
// 2. 遍历数组, 如果cnt=0, 表示没有候选人, 则选取当前数为候选人, ++cnt
// 3. 否则, 如果cnt > 0, 表示有候选人，如果当前数=cond，则++cnt，否则--cnt
// 4. 直到数组遍历完毕, 最后检查cnt是否为众数

class Solution3 {
    public:
        int MoreThanHalfNum_Solution(vector<int> numbers) {
            int cond = -1;
            int cnt = 0;
            for (int i = 0; i < numbers.size(); i++) {
                if (0 == cnt) {
                    cond = numbers[i];
                    cnt++;
                }
                else {
                    if (numbers[i] == cond) {
                        cnt++;
                    }
                    else {
                        cnt--;
                    }
                }
            }

            cnt = 0;

            for (auto k: numbers) {
                if (cond == k) {
                    cnt++;
                }
            }

            if (cnt > numbers.size() / 2) {
                return cond;
            }

            return 0;
        }
};


int main(int argc, char* argv[]) {

    vector<int> numbers = {9, 1, 1, 2, 3, 1, 9, 9, 9, 9, 9};

    Solution sol3;
    int res = sol3.MoreThanHalfNum_Solution(numbers);

    cout << res << endl;

    return 0;
}
