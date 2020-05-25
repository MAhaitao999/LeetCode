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
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int rootValue = pre[0];
		TreeNode* root = new TreeNode(pre[0]);

		return root;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}
