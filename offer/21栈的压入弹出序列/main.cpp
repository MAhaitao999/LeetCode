/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 11 Jun 2020 11:50:16 PM CST
 ************************************************************************/
// 输入两个整数序列, 第一个序列表示栈的压入顺序, 请判断第二个序列是否可能为该栈的弹出顺序.
// 假设压入栈的所有数字均不相等. 例如序列1, 2, 3, 4, 5是某栈的压入顺序, 序列4, 5, 3, 2, 1是
// 该压栈序列对应的一个弹出序列, 但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列.(注意: 这两个序列的长度是相等的)
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 新建一个栈, 将数组A压入栈中, 当栈顶元素等于数组B时,
// 就将其出栈, 当循环结束时, 判断栈是否为空, 若为空则
// 返回true.
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        cout << "pushV's size is: " << pushV.size() << endl;
        cout << "popV's size is: " << popV.size() << endl;
	    if(pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size()) {
            return false;
		}
		stack<int> sta;

        int j = 0;
		for (auto iter = pushV.begin(); iter < pushV.end(); iter++) {
		    sta.push(*iter);

			while (!sta.empty() && sta.top() == popV[j]) {
			    sta.pop();
				j++;
			}
		}
		return sta.empty();

	}
};

int main(int argc, char* argv[]) {

    vector<int> pushV = {1, 2, 3, 4, 5};
	vector<int> popV = {4, 5, 3, 2, 1};
    Solution sol;
	bool res = sol.IsPopOrder(pushV, popV);

	cout << res << endl;
    return 0;
}
