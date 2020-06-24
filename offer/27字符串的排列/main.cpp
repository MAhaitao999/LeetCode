/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon 22 Jun 2020 11:38:22 PM CST
 ************************************************************************/
// 题目描述:
// 输入一个字符串, 按字典序打印出该字符串中字符的所有排列. 
// 例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的
// 所有字符串abc, acb, bac, bca, cab 和cba.
// 输入描述:
// 输入一个字符串, 长度不超过9(可能有字符重复), 字符只包括大小写字母.
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> Permutation(string str) {
            if (str.empty()) {
                return {};
            }
            perm(0, str);
            // vector<string> aa = {"111", "222", "333"};
            // return vector<string>(aa);
            // return vector<string>({aa.begin(), aa.end()});
            return vector<string>{ret.begin(), ret.end()};
        }
    private:
        set<string> ret;
        void perm(int pos, string s) {
            if (pos == s.length() - 1) {
                ret.insert(s);
                for (auto iter = ret.begin(); iter != ret.end(); iter++) {
                    cout << *iter << " ";
                }
                cout << endl;
                return;
            }
            // for循环和swap的含义: 对于"ABC"
            // 第一次'A'与'A'交换, 字符串为"ABC", pos为0, 相当于固定'A'
            // 第二次'A'与'B'交换, 字符串为"BAC", pos为1, 相当于固定'B'
            // 第三次'A'与'C'交换, 字符串为"CBA", pos为2, 相当于固定'C'
            for (int i = pos; i < s.length(); ++i) {
                swap(s[pos], s[i]); // "ABC" --> "BAC"
                perm(pos+1, s);     // "AC" again perm operation
                swap(s[pos], s[i]); // "BAC" --> "ABC"

                // 回溯的原因: 比如第二次交换后是"BAC", 需要回溯到"ABC"
                // 然后进行第三次交换, 才能得到"CBA"
            }
        }

};

class Solution2 {
    public:
        vector<string> Permutation(string str) {
            if (str.empty()) {
                return {};
            }

            perm(0, str);
            return vector<string>({res.begin(), res.end()});
        }

    private:
        set<string> res; // set can automatically sort elements and remove duplication

        void perm(int pos, string str) {
            if (pos == str.size() - 1) {
                res.insert(str);
            }

            for (int i = pos; i < str.size(); i++) {
                swap(str[i], str[pos]);
                perm(pos+1, str);
                swap(str[pos], str[i]);
            }
        }
};


int main(int argc, char* argv[]) {

    string s = "AB";
    Solution2 sol;
    vector<string> res = sol.Permutation(s);
    for (auto iter = res.begin(); iter < res.end(); iter++) {
        cout << *iter << endl;
    }

    /*
    string str = "ABCDEFGHIJKLMN";
    cout << str[0] << endl;
    cout << str.length() << endl;
    cout << str.size() << endl;
    */

    /*
    swap(str[0], str[12]);

    set<string> ss;
    ss = {"ABC", "ACB", "BCA", "BAC"};
    for (auto iter = ss.begin(); iter != ss.end(); iter++) {
        cout << *iter << endl;
    }
    cout << str << endl;
    */
    return 0;
}
