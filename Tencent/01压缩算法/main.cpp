/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: 2020年05月22日 星期五 18时03分51秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

class Solution {

public:

    string decode(string encoded) {

        stack<char> sta;
        string decoded = "";
        int num = 0;
        string tmp1 = ""; // 记录重复的字符
        string tmp2 = ""; // 记录重复字符的次数, 再通过stoi函数转化为整型, 存在num中.
        
        // cout << encoded.size() << endl;
        
        // HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
        for (int i = 0; i < encoded.size(); i++) {
            if (encoded[i] != ']') {
                sta.push(encoded[i]);
                // cout << encoded[i];
            }
            else {
                tmp1 = "";
                while (sta.top() != '|') {
                    tmp1 += sta.top();
                    sta.pop();
                }
                reverse(tmp1.begin(), tmp1.end());
                // cout << tmp1 << endl;

                sta.pop(); // pop '|'
                tmp2 = "";
                while (sta.top() != '[') {
                    tmp2 += sta.top();
                    sta.pop();
                }
                reverse(tmp2.begin(), tmp2.end());
                num = stoi(tmp2);
                // cout << num << endl;

                string str = "";
                for (int i = 0; i < num; i++) {
                    str += tmp1;
                }

                // cout << str << endl;

                sta.pop(); // pop '['

                for(auto c:str) {
                    // cout << c << endl;
                    sta.push(c);
                }

            }
        }

        /*
        stack<char> s2;
        s2 = sta;
        cout << "------------" << endl;
        while(!s2.empty()){
            cout << s2.top() << endl;
            s2.pop();
        }
        cout << "------------" << endl;
        */
        while (!sta.empty()) {
            decoded += sta.top();
            sta.pop();
        }

        /*
        cout << "+++++++++++++" << endl;
        cout << decoded << endl;
        cout << "+++++++++++++" << endl;
        */

        reverse(decoded.begin(), decoded.end());
        // cout << decoded << endl;
        return decoded;
    }

};


int main(int argc, char* argv[]) {

    string s;
    cin >> s;
    Solution sol;
    string decoded = sol.decode(s);

    cout << decoded << endl;

    return 0;
}

// HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
