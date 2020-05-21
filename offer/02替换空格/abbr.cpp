/*************************************************************************
    > File Name: abbr2.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Fri 22 May 2020 12:36:21 AM CST
 ************************************************************************/

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void abbr(char *str, int length) {
			// cout << str << endl;
            int count = 0;
            vector<int> idx;
            for (int i = 0; i < length; i++) {
                if (str[i] == ' ') {
                    count++;
                    idx.push_back(i+1);
                }
            }
            // cout << "" << endl;
            char tmp[count+2];
            tmp[0] = str[0];
            for (int i = 0; i < idx.size(); i++) {
                tmp[i+1] = str[idx[i]]; 
            }
            tmp[count+1] = '\0';
            // cout << tmp << endl;
            strcpy(str, tmp);
        }
};

int main(int argc, char* argv[]) {
    
    Solution sol;
    char str[100];
    scanf("%[^\n]", str);
    sol.abbr(str, strlen(str));
    cout << str;
	cout << endl;
    return 0;
}
