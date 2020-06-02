/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sat 30 May 2020 08:58:33 PM CST
 ************************************************************************/

// 输入一个整数, 输出该数二进制表示中1的个数. 其中负数用补码表示.
#include <iostream>
using namespace std;

// 方法1: 二进制移位法
class Solution1 {
public:
	int NumberOf1(int n) {
	    int nbits = sizeof(int) * 8;
		cout << "在本机器上int类型是" << nbits << "比特!" << endl;
		int mask = 0x01;
		int count = 0;
		while (mask != 0) { 
			if (mask & n) {
			    count++;
			}
            mask <<= 1;
			// cout << "mask is: " << mask << endl;
		}

		return count;
	}
};

// 方法二:
// 对于上一种解法中, 无用操作是: 如果当前位是0, 还是会做判断, 然后一位一位地移动.
// 如果, 给你一种超能力, 你一下可以对从右向左的第一位1直接判断, 遇到0直接略过, 那效率是不是很快.
// 现考虑二进制数: val:1101000, val-1:1100111 那么val&(val-1): 1100000
// 如果你会了这个操作, 是不是这题就很简单了.
class Solution2 {
public: 
    int NumberOf1(int n) {
	    int nbits = sizeof(int) * 8;
		cout << "在本机器上int类型是" << nbits << "比特!" << endl;
		int count = 0;
		while (n != 0) {
			// cout << n << endl;
		    count++;
			n &= (n-1);
		}
		return count;
	}
};


int main(int argc, char* argv[]) {
    
    int res = 0;
    Solution2 sol2;	
	res = sol2.NumberOf1(3);
	cout << res << endl;
    return 0;
}
