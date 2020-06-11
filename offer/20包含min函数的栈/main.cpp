/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 11 Jun 2020 10:50:15 PM CST
 ************************************************************************/
// 定义栈的数据结构, 请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1)).
// 注意: 保证测试中不会当栈为空的时候, 对栈调用pop()或者min()或者top()方法.

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        normal.push(value);
		if (minval.empty()) {
		    minval.push(value);
		}
		else {
		    if (value < minval.top()) {
			    minval.push(value);
			}
			else {
			    minval.push(minval.top());
			}
		}
	}

	void pop() {
        normal.pop();
		minval.pop();
	}

	int top() {
        return normal.top();
	}

	int min() {
	    return minval.top();
	}

private:
    stack<int> normal, minval;
};

/*
class Solution {
public:
    void push(int value) {
        normal.push(value);
        if (minval.empty()) {
            minval.push(value);
        }
        else {
            if (normal.top() > value) {
                minval.push(value);
            }
            else {
                minval.push(minval.top());
            }
        }
        
    }
    void pop() {
        normal.pop();
        minval.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return minval.top();
    }
    
private:
    stack<int> normal, minval;
};
*/

int main(int argc, char* argv[]) {
    Solution sol;
	sol.push(3);
	cout << sol.min() << " ";
	sol.push(4);
	cout << sol.min() << " ";
	sol.push(2);
	cout << sol.min() << " ";
	sol.push(3);
	cout << sol.min() << " ";
	sol.pop();
	cout << sol.min() << " ";
	sol.pop();
	cout << sol.min() << " ";
	sol.pop();
	cout << sol.min() << " ";
	sol.push(0);
	cout << sol.min() << " ";

	cout << endl;
    return 0;
}
