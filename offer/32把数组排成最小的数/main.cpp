/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sat 11 Jul 2020 05:08:39 PM CST
 ************************************************************************/
// 题目描述:
// 输入一个正整数数组, 把数组里所有数字拼接起来排成一个数, 
// 打印能拼接出的所有数字中最小的一个. 例如输入数组{3, 32, 321},
// 则打印出这三个数字能排成的最小数字为321323.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string PrintMinNumber(vector<int> numbers) {

            string res = "";
            if (0 == numbers.size()) {
                return res;
            }

            sort(numbers.begin(), numbers.end(), compare);
            for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
            
                res += to_string(*iter);
            }
            return res;
        }

    private:
        static bool compare(int a, int b) {
            if ((to_string(a) + to_string(b)) < (to_string(b) + to_string(a))) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main(int argc, char* argv[]) {

    vector<int> num = {1, 3, 21, 23, 45, 32, 56, 78, 12, 25};

    Solution sol;
    string res = sol.PrintMinNumber(num);

    cout << res << endl;

    return 0;
}
