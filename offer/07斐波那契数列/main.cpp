/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 28 May 2020 10:00:21 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {

        if (n == 0 || n == 1) {
		    return n;
		}
        int f = 0;
		int g = 1;
		while (n > 1) {
		    g = f + g;
			f = g - f;
			n--;
		}
		return g;
	}
};

int main(int argc, char* argv[]) {

    vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
	Solution sol;
	int res = 0;
	for (auto iter = num.begin(); iter < num.end(); iter++) {
	    res = sol.Fibonacci(*iter);
	    cout << "when n = " << *iter << ", The fibonacci num is: " << res << endl;
	}
    return 0;
}
