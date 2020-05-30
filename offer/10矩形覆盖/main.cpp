/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sat 30 May 2020 08:22:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 方法1: 递归法
class Solution1 {
public:
	int rectCover(int number) {
		if (number < 0) {
		    // cout << "number 必须大于等于0!" << endl;
			// return;
			throw "number must be greater than or equal to 0!";
		}
		else if (number == 0 || number == 1 || number == 2) {
		    return number;
		}
		else {
		    return rectCover(number-1) + rectCover(number-2);
		}
	}
	
};

// 方法2: 迭代法
class Solution2 {
public:
	int rectCover(int number) {
	    if (number < 0) {
		    // cout << "number必须大于等于0!" << endl;
			// return;
			throw "number must be grater than or equal to 0";
		}
		else if (number == 0 || number == 1 || number == 2) {
		    return number;
		}
		else {
			int f = 1;
			int g = 2;
		    while (number > 2) {
			    g = f + g;
				f = g - f;
				number--;
			}
			return g;
		}
	}
};


int main(int argc, char* argv[]) {

    vector<int> number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int res;
    Solution1 sol1;
	for (auto iter = number.begin(); iter < number.end(); iter++) {
	    res = sol1.rectCover(*iter);
		cout << "f(" << *iter << ")= " << res << endl;
	}

	cout << "********************" << endl;

    Solution2 sol2;
	for (auto iter = number.begin(); iter < number.end(); iter++) {
	    res = sol2.rectCover(*iter);
		cout << "f(" << *iter << ")= " << res << endl;
	}

    return 0;
}
