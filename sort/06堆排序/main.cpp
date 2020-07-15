/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue Jul 14 19:23:46 2020
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 堆排序
// 堆排序(Heapsort)是指利用堆这种数据结构所设计的一种排序算法. 堆积是一个近似
// 完全二叉树的结构, 并同时满足堆积的性质: 即子节点的键值或索引总是小于(或者大于)
// 它的父节点. 堆排序可以说是一种利用堆的概念来排序的选择排序. 分为两种方法:
// 1. 大顶堆: 每个节点的值都大于或等于其子节点的值, 在堆排序算法中用于升序排列;
// 2. 小顶堆: 每个节点的值都小于或等于其子节点的值, 在堆排序算法中用于降序排列;
// 堆排序的平均时间复杂度为O(nlogn).
// 算法步骤:
// 1. 将待排序序列构建成一个堆H[0, 1, ..., n-1], 根据(升序降序需求)选择大顶堆或小顶堆;
// 2. 把堆首(最大值)和堆尾互换;
// 3. 把堆的尺寸缩小1, 并调用build_heap, 目的是把新的数组顶端数据调整到相应位置;
// 4. 重复步骤2, 直到堆的尺寸为1.

class Solution {
    public:
        void heap_sort(vector<int>& arr) {
            int n = arr.size();
            int* tmp = new int(n);

            for (int i = 0; i < n; i++) {
                tmp[i] = arr[i];
            }

            heap_sort_base(tmp, n);

            for (int i = 0; i < n; i++) {
                arr[i] = tmp[i];
            }
        }

    private:
        void heaplify(int tree[], int n, int i) {
            /*n表示数组长度, i表示某个父节点*/
            if (i >= n) {
                return;
            }

            int parent =  (i - 1) / 2;
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            int max = i;

            if (c1 < n && tree[max] < tree[c1]) {
                max = c1;
            }
            if (c2 < n && tree[max] < tree[c2]) {
                max = c2;
            }

            if (i != max) {
                swap(tree[i], tree[max]);
                heaplify(tree, n, max); // build_heap必须保留这个递归, 如果是排序的话只要求保证堆顶为最大值即可, 可以省略.
            }

        }

        void build_heap(int tree[], int n) {
            int last_node = n - 1;
            int parent = (last_node - 1) / 2;
            for (int i = parent; i >=0; i--) {
                heaplify(tree, n, i);
            }
        }

        void heap_sort_base(int arr[], int n) {
            
            for (int i = n; i > 0; i--) {
                build_heap(arr, i);
                swap(arr[0], arr[i-1]);
            }
        }
};


int main(int argc, char* argv[]) {

    // vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9,
    //                    5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9, 3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4, 5};
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3};
    // vector<int> arr = {1};
    // vector<int> arr = {};

    Solution sol;
    sol.heap_sort(arr);

    for (auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
