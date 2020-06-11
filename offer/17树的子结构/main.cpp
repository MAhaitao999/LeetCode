/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon 08 Jun 2020 11:41:54 PM CST
 ************************************************************************/
// 输入两棵二叉树A, B, 判断B是不是A的子结构. (ps: 我们约定空树不是任意一个树的子结构)

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) {
            return false;
        }
		else {
			return dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
		}
    }

private:
	bool dfs(TreeNode* r1, TreeNode* r2) {
	    if (!r2) return true;
		if (!r1) return false;
		return r1->val == r2->val && dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
	}
};

int main(int argc, char* argv[]) {
    
	// Tree A
    TreeNode An3(3);
	TreeNode An4(4);
	TreeNode An1(1);
	TreeNode An2(2);
	TreeNode An5(5);

	An3.left = &An4;
	An3.right = &An5;
	An4.left = &An1;
	An4.right = &An2;

	// Tree B
	TreeNode Bn4(3);
	TreeNode Bn1(4);

	Bn4.left = &Bn1;

	// Solution
	Solution sol;
	bool res = sol.HasSubtree(&An3, &Bn4);
	cout << "res is: " << res << endl;
    return 0;
}
