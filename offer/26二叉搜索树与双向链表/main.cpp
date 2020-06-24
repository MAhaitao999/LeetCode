/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sun 21 Jun 2020 10:06:03 PM CST
 ************************************************************************/
// 题目描述:
// 输入一棵二叉搜索树, 将该二叉搜索树转换成一个排序的双向链表, 要求不能创建任何新的
// 结点, 只能调整树中结点指针的指向.
#include <iostream>
#include <algorithm>

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
        TreeNode* Convert(TreeNode* pRootOfTree) {
            if (!pRootOfTree) {
                return NULL;
            }
            auto pairs = dfs(pRootOfTree);
            // 头和尾相互指向, 加上之后牛客网过不了
            // pairs.first->left = pairs.second;
            // pairs.second->right = pairs.first;
            return pairs.first;

        }

    private:
        pair<TreeNode*, TreeNode*> dfs(TreeNode* root) { // pair第一个元素是链表的头, 第二个元素是链表的尾
            if (!root->left && !root->right) { // 如果左右子节点都没有, 则返回的是链表头和尾都是root
                return {root, root};
            }

            if (root->left && root->right) { // 如果左右子节点都存在:
                                             // 则左子树所对应的链表尾与root相互指向;
                                             // 右子树所对应的链表头与root相互指向; 
                                             // 返回的链表头为左子树所对应链表的头;
                                             // 返回的链表尾为右子树所对应链表的尾.
                auto leftsides = dfs(root->left);
                auto rightsides = dfs(root->right);
                root->left = leftsides.second;
                (leftsides.second)->right = root;
                root->right = rightsides.first;
                (rightsides.first)->left = root;

                return {leftsides.first, rightsides.second};
            }

            if (root->left && !root->right) { // 左子树存在而右子树不存在
                auto leftsides = dfs(root->left);
                root->left = leftsides.second;
                (leftsides.second)->right = root;

                return {leftsides.first, root};
            }

            if (!root->left && root->right) {
                auto rightsides = dfs(root->right);
                root->right = rightsides.first;
                (rightsides.first)->left = root;

                return {root, rightsides.second};
            }
        }
};

int main(int argc, char* argv[]) {
    
    TreeNode n4(4);
    TreeNode n2(2);
    TreeNode n6(6);
    TreeNode n1(1);
    TreeNode n3(3);
    TreeNode n5(5);
    TreeNode n7(7);

    n4.left = &n2;
    n4.right = &n6;
    n2.left = &n1;
    n2.right = &n3;
    n6.left = &n5;
    n6.right = &n7;

    Solution sol;
    TreeNode* phead = sol.Convert(&n4);
    TreeNode* p1 = phead;

    while (p1->right != NULL) {
        cout << p1->val << " ";
        p1 = p1->right;
    }
    cout << p1->val << endl;

    TreeNode* p2 = p1;
    while (p2->left != NULL) {
        cout << p2->val << " ";
        p2 = p2->left;
    }

    cout << p2->val << endl;
    return 0;
}
