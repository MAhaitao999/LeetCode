/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sun 05 Jul 2020 10:24:48 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 题目描述:
// 输入n个整数, 找出其中最小的K个数. 例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字, 
// 则最小的4个数字是1, 2, 3, 4.

class Solution {
    public:
        vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
            
            vector<int> ret;
            if (k == 0 || k > input.size()) {
                return ret;
            }

            priority_queue<int, vector<int>, less<int> > pq; // 大顶堆

            for (auto iter = input.begin(); iter < input.end(); iter++) {
                if (pq.size() < k) {
                    pq.push(*iter);
                }
                else {
                    if (pq.top() > *iter) {
                        pq.pop();
                        pq.push(*iter);
                    }
                }
            }

            while (!pq.empty()) {
                ret.push_back(pq.top());
                pq.pop();
            }

            return ret;
        }
};
int main(int argc, char* argv[]) {

    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8, 17, 22, 11, 26, 78, 23, 1, 2, 5, 4, 8, 9, 10, 11, 246, 43, 273, 112, 43, 56, 67};
    int k = 4;
    Solution sol;
    vector<int> ret = sol.GetLeastNumbers_Solution(input, k);

    for (auto iter = ret.begin(); iter < ret.end(); iter++) {
        cout << *iter << " ";
    }

    cout << endl;

    return 0;
}
