/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon 01 Jun 2020 10:47:26 PM CST
 ************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

// 方法1: 内置函数
class Solution1 {
public:
    double Power(double base, int exponent) {
        return pow(base, exponent);
	}
};

// 方法2: 暴力法
class Solution2 {
public:
    double Power(double base, int exponent) {
		if (base == 0) {
		    return 0.0;
		}

	    if (exponent == 0) {
		    return 1.0;
		}
		else if (exponent > 0) {
            double res = 1.0;
		    while (exponent > 0) {
			    res *= base;
				exponent--;
			}
			return res;
		}
		else {
		    double res = 1.0;
			while (exponent < 0) {
			    res /= base;
				exponent++;
			}
			return res;
		}
	}
};

// 方法3: 递归法
class Solution3 {
public:
	double Power(double base, int exponent) {
	    if (base == 0.0) {
		    return 0;
		}
		if (exponent == 0) {
		    return 1.0;
		}
		if (exponent == 1) {
		    return base;
		}
		if (exponent == -1) {
		    return 1./base;
		}

		return Power(base, exponent/2) * Power(base, exponent/2) * Power(base, exponent%2);
	}
};

// 方法4: 迭代法
class Solution4 {
public:
    double Power(double base, int exponent) {
		if (base == 0.0) {
		    return 0;
		}

	    if (exponent == 0) {
		    return 1.0;
		}
		else if (exponent > 0) {
            double res = 1.0;
			while (exponent != 0) {
				// cout << "exponent is: " << exponent << endl;
		        if (exponent & 1) {
			        res *= base;
					// cout << "----res is: " << res << endl;
			    }
				exponent >>= 1;
			    base = base * base;
			}
			return res;
		}
		else {
		    base = 1./base;
			exponent = -exponent;
			double res = 1.0;
			while (exponent != 0) {
			    if (exponent & 1) {
				    res *= base;
				}
				exponent >>= 1;
				base = base * base;
			}
			return res;
		}
	}
};

int main(int argc, char* argv[]) {

    double base = 0;
	int exponent = -1;
	double res = 0;

	Solution1 sol1;
	res = sol1.Power(base, exponent);
	cout << res << endl;

	Solution2 sol2;
	res = sol2.Power(base, exponent);
	cout << res << endl;

	Solution3 sol3;
	res = sol3.Power(base, exponent);
	cout << res << endl;

	Solution4 sol4;
	res = sol4.Power(base, exponent);
	cout << res << endl;
    return 0;
}
