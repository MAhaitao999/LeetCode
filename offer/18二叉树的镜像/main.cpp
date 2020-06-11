/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 10 Jun 2020 01:04:09 AM CST
 ************************************************************************/

#include <iostream>
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

class Solution {
public:
    void Mirror(TreeNode* pRoot) {
        if (!pRoot) {
		    return;
		}
        TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

void PreOrder(TreeNode* bt) {
    if (bt == NULL) {
	    return;
	}
	else {
	    cout << bt->val << " ";
		PreOrder(bt->left);
		PreOrder(bt->right);
	}
}

int main(int argc, char* argv[]) {
	
	TreeNode n8(8);
	TreeNode n6(6);
	TreeNode n10(10);
	TreeNode n5(5);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n11(11);

	n8.left = &n6;
	n8.right = &n10;
	n6.left = &n5;
	n6.right = &n7;
	n10.left = &n9;
	n10.right = &n11;

	PreOrder(&n8);
	cout << endl;

	Solution sol;
	sol.Mirror(&n8);
	PreOrder(&n8);
	cout << endl;

    return 0;
}
