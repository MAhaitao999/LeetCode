/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 28 May 2020 10:39:49 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

/*方案一: 递归法*/
class Solution1 {
public:
    int jumpFloor(int number) {
	    if (number == 1) {
		    return 1;
		}
		else if (number == 2) {
		    return 2;
		}
		else {
		    return 1*jumpFloor(number-1) + 1*jumpFloor(number-2);
		}
	}
};

/*方法二: 迭代法*/
class Solution2 {
public:
    int jumpFloor(int number) {
		if (number == 1 || number == 2) {
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

    int number = 50;
    Solution1 sol1;
	Solution2 sol2;
	int res1 = sol1.jumpFloor(number);
	int res2 = sol2.jumpFloor(number);
	cout << res1 << endl;
	cout << res2 << endl;

    return 0;
}
