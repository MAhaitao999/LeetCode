/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue 16 Jun 2020 09:46:27 PM CST
 ************************************************************************/
// 题目描述:
// 输入一个整数数组, 判断该数组是不是某**二叉搜索树**的后续遍历的结果. 如果是
// 则输出Yes, 否则输出No. 假设输入的数组的任意两个数字都不相同.
// 二叉搜索树: 所有左子树上的数小于根节点, 所有右子树上的数大于根节点.
// 解体参考: 
// cuijiahua.com/blog/2017/12/basis_23.html
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool VerifySquenceOfBST(vector<int> sequence) {
            return bst(sequence, 0, sequence.size() - 1);
        }

    private:
        bool bst(vector<int> seq, int begin, int end) {
            if (seq.empty() || begin > end) {
                return false;
            }

            // 确定根节点
            int root = seq[end];

            int i = begin;
            // 确定左子树的位置, 左子树的节点小于根节点
            for (; i < end; i++) {
                if(seq[i] > root) {
                    break;
                }
            }

            // 如果在右子树中有节点小于根节点, 则直接返回false
            for (int j = i; j < end; j++) {
                if (seq[j] < root) {
                    return false;
                }
            }

            // 左子树的序列为seq[begin, i-1]
            // cout << "pos is: " << (i-1) << endl;
            bool left = true;
            if (begin < i) { // 否则的话左子树为空或者只有一个元素, left均为true
                left = bst(seq, begin, i - 1);
            }
            // 右子树的序列为seq[i, end-1]
            bool right = true;
            if (i < end - 1) { // 否则的话右子树为空或者只有一个元素, right均为true
                right = bst(seq, i, end - 1);
            }
            return left && right; // 只有当左子树和右子树均为二叉搜索树的时候才为true
        }
};

int main(int argc, char* argv[]) {

    vector<int> sequence = {4, 8, 6, 12, 14, 10};
    // vector<int> sequence = {};
    Solution sol;
    bool result = sol.VerifySquenceOfBST(sequence);
    cout << result << endl;
    return 0;
}
