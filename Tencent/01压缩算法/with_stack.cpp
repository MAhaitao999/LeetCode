#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {

    string s;
    cin >> s;
    stack<char> sta;
    int i = 0;
    while (i < s.size()) {
        if (s[i] != ']') {
            sta.push(s[i++]);
        }
        else { // s[i] == ']'
            string tmp = "";
            while (sta.top() != '|') {
                tmp += sta.top();
                sta.pop();
            }
            reverse(tmp.begin(), tmp.end());
            sta.pop(); // pop掉'|'
            string str = tmp;
            tmp="";
            while(sta.top() != '[') {
                tmp += sta.top();
                sta.pop();
            }
            
            reverse(tmp.begin(), tmp.end());
            int num = stoi(tmp);
            sta.pop(); // pop '['
            tmp = "";
            while (num > 0) {
                tmp += str;
                num--;
            }
            for (char& c:tmp) {
                sta.push(c);
            }
            ++i;
        }
    }

    string res = "";
    while (!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}

// HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
