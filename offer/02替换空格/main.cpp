/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 21 May 2020 09:47:53 PM CST
 ************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

class Solution1 {
public:

    void replaceSpace(char* str, int length) {
        // cout << str << endl;
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                count++;
            }
        }
        char tmp[2 * count + length + 1];
        count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == 32) {
                tmp[i + 2 * count] = '%';
                tmp[i + 2 * count + 1] = '2';
                tmp[i + 2 * count + 2] = 'B';
                count++;
            } else {
                tmp[i + 2 * count] = str[i];
            }
        }
        tmp[2 * count + length] = '\0';
        strcpy(str, tmp);
    }
};

class Solution2 {
public:

    void replaceSpace(char str[], int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                count++;
            }
        }
        char *p1 = &str[length];
        char *p2 = &str[length + 2 * count];
        while (p1 != p2) {
            if (*p1 == ' ') {
                *p2-- = 'B';
                *p2-- = '2';
                *p2-- = '%';
            } else {
                *p2-- = *p1;
            }
            p1--;
        }
    }
};

int main(int argc, char* argv[]) {

    /*
        char s[] = "We     Are Happy";
        cout << "origin str is: " << s << endl;
        Solution1 sol1;
        sol1.replaceSpace(s, strlen(s));
        // char c = ' ';
        // cout  << int(c) << endl;
        cout << "after replace, the str is: " << s << endl;
     */

    char ss[] = "We are happy";
    cout << "origin str is: " << ss << endl;

    Solution2 sol2;
    sol2.replaceSpace(ss, strlen(ss));
    cout << "after replace, the str is: " << ss << endl;
    return 0;
}
