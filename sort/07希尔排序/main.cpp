/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed Jul 15 15:44:15 2020
 ************************************************************************/
// 希尔排序, 也称递减增量排序算法, 是插入排序的一种更高效的改进版本. 但是希尔
// 排序是非稳定排序算法.
// 希尔排序是基于插入排序的以下两个性质而提出改进方法的:
// 1. 插入排序在对几乎已经排序好的数据操作时, 效率高, 即可以达到线性排序的效率.
// 2. 但插入排序一般来说是低效的, 因为插入排序每次只能将数据移动一位.

// 希尔排序的基本思想是: 先将整个待排序的记录序列分割成若干个子序列分别进行直接
// 插入排序, 待整个序列中的记录"基本有序"时, 再对全体记录进行依次直接插入排序.
// 算法步骤:
// 选择一个增量序列t1, t2, ..., tk, 其中ti > tj, tk = 1;
// 按增量序列个数k, 对序列进行k趟排序;
// 每趟排序, 根据对应的增量ti, 将待排序列分割成若干长度为m的子序列, 分别对各子表
// 进行直接插入排序. 仅增量因子为1时, 整个序列作为一个表来处理, 表长度即为整个序列的长度.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void shell_sort(vector<int>& arr) {
            int n = arr.size();
            // 原始的插入排序
            /*
            for (int i = 1; i < n; i++) {
                for (int j = i; j > 0; j--) {
                    if (arr[j] < arr[j-1]) {
                        swap(arr[j], arr[j-1]);
                    }
                }
            }
            */

            // 展开版本的shell排序
            /*
            int gap = 4;
            for (int i = gap; i < n; i++) {
                cout << "ii" << i << endl;
                for (int j = i; j > gap - 1; j -= gap) {
                    if (arr[j] < arr[j-gap]) {
                        swap(arr[j], arr[j-gap]);
                    }
                }
            }

            gap = 2;
            for (int i = gap; i < n; i++) {
                for (int j = i; j > gap - 1; j-= gap) {
                    if (arr[j] < arr[j-gap]) {
                        swap(arr[j], arr[j-gap]);
                    }
                }
            }

            gap = 1;
            for (int i = gap; i < n; i++) {
                for (int j = i; j > gap - 1; j-= gap) {
                    if (arr[j] < arr[j-gap]) {
                        swap(arr[j], arr[j-gap]);
                    }
                }
            }
            */

            // 原始版本的shell排序
            /*
            for (int gap = n/2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i++) {
                    for (int j = i; j > gap-1 ; j -= gap) {
                        if (arr[j] < arr[j-gap]) {
                            swap(arr[j], arr[j-gap]);
                        }
                    }
                }
            }
            */

            // knuth版本的shell排序
            // h = 1
            // h = 3*h + 1
            int h = 1;
            while (h <= n/3) {
                h = h*3 + 1;
            }

            for (int gap = h; gap > 0; gap = (gap - 1) / 3) {
                for (int i = gap; i < n; i++) {
                    for (int j = i; j > gap-1 ; j -= gap) {
                        if (arr[j] < arr[j-gap]) {
                            swap(arr[j], arr[j-gap]);
                        }
                    }
                }
            }
        }
};

int main(int argc, char* argv[]) {

    vector<int> arr = {9, 6, 11, 3, 5, 12, 8, 7, 10, 15, 14, 4, 1, 13, 2};
    // vector<int> arr = {1};
    // vector<int> arr = {};
    Solution sol;
    sol.shell_sort(arr);
    for (auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
