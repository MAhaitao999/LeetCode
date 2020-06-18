
/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue Jun 16 09:06:34 2020
 ************************************************************************/
// 题目描述:
// 从上往下打印出二叉树的每个节点, 同层节点从左至右打印.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
     TreeNode(int x):val(x), left(NULL), right(NULL) {
}};

class Solution {
  public:
    vector < int >PrintFromTopToBottom(TreeNode * root) {
	vector < int >out = { };

	queue < TreeNode * >q;
	TreeNode *front = NULL;

	if (NULL != root) {
	    q.push(root);
	}

	while (!q.empty()) {
	    front = q.front();
	    out.push_back(front->val);
	    if (front->left != NULL) {
		q.push(front->left);
	    }
	    if (front->right != NULL) {
		q.push(front->right);
	    }
	    q.pop();
	}

	return out;
    }
};

int main(int argc, char *argv[])
{

    /*
       queue<string> q;
       q.push("Hello world!");
       q.push("China");
       q.pop();
       cout << q.front() << endl;
       cout << q.size() << endl;
       cout << q.empty() << endl;
       cout << q.front() << endl;
       cout << q.back() << endl;
     */
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    // n2.right = &n5;
    // n3.left = &n6;
    n3.right = &n7;

    Solution sol;
    vector < int >result = sol.PrintFromTopToBottom(NULL);

    for (auto iter = result.begin(); iter < result.end(); iter++) {
	cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
