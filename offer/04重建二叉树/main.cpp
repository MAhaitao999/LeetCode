/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon 25 May 2020 11:03:10 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 前序遍历序列{1, 2, 4, 7, 3, 5, 6, 8} 和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}
// 思路: 先序遍历数组中的第一个数为根节点的值, 然后从中序遍历的数组中找到这个值
// 所在位置, 则左边的数就是左子树的元素, 右边的数就是右子树的元素, 分别递归得到
// 左子树和右子树.
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        cout << "in stack i" << endl;
        // 递归出口
		if (pre.empty() || vin.empty()) {
		    return new TreeNode(0);
		}

		int pos = 0;
        int rootValue = pre[0];
		for (int i = 0; i < vin.size(); i++) {
		    if (rootValue == vin[i]) {
			    pos = i;
				break;
			}
			else {
			    continue;
			}
		}

		cout << "pos is: " << pos << endl;

		vector<int> left_vin(vin.begin(), vin.begin()+pos);
		cout << "left_vin's size is: " << left_vin.size() << endl;
		for (auto iter = left_vin.begin(); iter < left_vin.end(); iter++) {
		    cout << *iter << ", ";
		}
		cout << endl;

		vector<int> left_pre(pre.begin()+1, pre.begin()+pos+1);
		cout << "left_pre's size is: " << left_pre.size() << endl;
		for (auto iter = left_pre.begin(); iter < left_pre.end(); iter++) {
		    cout << *iter << ", ";
		}
		cout << endl;

		vector<int> right_vin(vin.begin()+pos+1, vin.end());
		cout << "right_vin's size is: " << right_vin.size() << endl;
		for (auto iter = right_vin.begin(); iter < right_vin.end(); iter++) {
		    cout << *iter << ", ";
		}
		cout << endl;

		vector<int> right_pre(pre.begin()+pos+1, pre.end());
		cout << "right_pre's size is: " << right_pre.size() << endl;
		for (auto iter = right_pre.begin(); iter < right_pre.end(); iter++) {
		    cout << *iter << ", ";
		}
		cout << endl;

		TreeNode* root = new TreeNode(pre[0]);
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);

		return root;
    }
};

int main(int argc, char* argv[]) {

	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
	for (auto iter = pre.begin(); iter < pre.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;

	for (auto iter = vin.begin(); iter < vin.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;
	Solution sol;
	sol.reConstructBinaryTree(pre, vin);

    return 0;
}
