/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 17 Jun 2020 10:13:01 PM CST
 ************************************************************************/
// 题目描述:
// 输入一个二叉树的根节点和一个整数, 按字典序打印处二叉树中结点值的和为输入整数的所有路径.
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径.
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): 
        val(x), left(NULL), right(NULL) {
            ;
        }
};

// 方法1: 递归法
class Solution {
    public:
        vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
            dfs(root, expectNumber);
            return res;
        }

        void dfs(TreeNode* root, int expectNumber) {
            if (NULL == root) {
                return;
            }

            path.push_back(root->val);
            expectNumber -= root->val;
            // expectNumber == 0 且找到了叶节点, 确定一条路径
            if (0 == expectNumber && NULL == root->left && NULL == root->right) {
                res.push_back(path);
            }

            dfs(root->left, expectNumber);
            dfs(root->right, expectNumber);
            path.pop_back();
        }

    private:
        vector<int> path;
        vector<vector<int> > res;
};

int main(int argc, char* argv[]) {

    TreeNode n10(10);
    TreeNode n5(5);
    TreeNode n12(12);
    TreeNode n4(4);
    TreeNode n7(7);

    n10.left = &n5;
    n10.right = &n12;
    n5.left = &n4;
    n5.right = &n7;

    Solution sol;
    vector<vector<int> > res = sol.FindPath(&n10, 22);

    for (int i = 0; i < res.size(); i++) {
        cout << "--------------------" << endl;
        for (auto iter = res[i].begin(); iter < res[i].end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
    }

    return 0;
}
