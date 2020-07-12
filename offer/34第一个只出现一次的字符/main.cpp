/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sun 12 Jul 2020 01:04:04 AM CST
 ************************************************************************/
// 题目描述:
// 在一个字符串(0<=字符串长度<=10000, 全部由字母组成)
// 中找到第一个只出现一次的字符, 并返回它的位置, 
// 如果没有则返回-1(需要区分大小写). (从0开始计数)
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        int PrintNotRepeatingChar(string str) {
            map<char, int> mp;
            for (auto c : str) {
                mp[c] += 1;
            }

            for (int i = 0; i < str.length(); ++i) {
                if (1 == mp[str[i]]) {
                    return i;
                }
            }

            return -1;
        }

};
int main(int argc, char* argv[]) {

    string str = "aaabbbcccdddessdfswskldksdkjfhdjkHHSLFSLDAHSDJAGYsdkjsdhfsh";
    Solution sol;
    int res = sol.PrintNotRepeatingChar(str);
    cout << res << endl;

    return 0;
}
