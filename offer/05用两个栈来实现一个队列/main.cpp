/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: 2020年05月27日 星期三 09时00分54秒
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {

        // 如果两个栈都是为空的话, 说明队列为空.
        if (stack1.empty() && stack2.empty()) {
            cout << "the queue is empty!" << endl;
        }

        if (!stack2.empty()) {
            int res1 = stack2.top();
            stack2.pop();
            return res1;
        }
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

};
int main(int argc, char* argv[]) {

    Solution sol;

    return 0;
}

/*
用例:
["PSH1","PSH2","PSH3","POP","POP","PSH4","POP","PSH5","POP","POP"]

对应输出应该为:

1,2,3,4,5
*/
