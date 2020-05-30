/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sat 30 May 2020 08:52:45 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
        if (number == 1 || number == 2) {
		    return number;
		}	    
		else {
            int res = 2;
		    while (number > 2) {
                res *= 2;
				number--;
			}
			return res;
		}
	}
};

int main(int argc, char* argv[]) {

    Solution sol;
	vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8 ,9, 10};
    int res;
	for (auto iter = number.begin(); iter < number.end(); iter++) {
	    res = sol.jumpFloorII(*iter);
		cout << "f(" << *iter << ") = " << res << endl;
	}
    return 0;
}
