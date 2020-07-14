/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon Jul 13 17:36:17 2020
 ************************************************************************/
// 快速排序是对冒泡排序的一种改进.
// 快速排序由C. A. R. Hoare在1962年提出.
// 它的基本思想是:
// 通过一趟排序将要排序的数据分割成独立的两部分, 其中一部分的所有数据比另一
// 部分的所有数据都要小, 然后再按此方法对这两部分数据分别进行快速排序, 整个
// 排序过程可以递归进行, 以次达到整个数据变成有序序列.
// 1. 选定Pivot中心轴
// 2. 将大于Pivot的数字放在Pivot右边
// 3. 将小于Pivot的数字放在Pivot左边
// 4. 分别对左右子序列重复前三步操作.
#include <iostream>
#include <vector>

using namespace std;

// 参考<<算法导论>>
// 伪代码:
/*
QUICKSORT(A, p, r)
  if p < r
    q = PARTITION(A, p, r)
    QUICKSORT(A, p, q-1)
    QUICKSORT(A, q+1, r)

PARTITION(A, p, r)
  x = A[r]
  i = p-1
  for j = p to r-1
    if A[j] < x
      i++
      swap(A[j], A[i])
  swap(A[i+1], A[r])
  return i+1
 * */

class Solution {
    public:
        void quick_sort(vector<int>& arr) {
            quick_sort_base(arr, 0, arr.size()-1);
        }

    private:
        void quick_sort_base(vector<int>& arr, int p, int r) {
            if (p < r) {
                int q = partition(arr, p, r);
                quick_sort_base(arr, p, q-1);
                quick_sort_base(arr, q+1, r);
            }
        }

        int partition(vector<int>& arr, int p, int r) {
            int x = arr[r];
            int i = p - 1;

            for (int j = p; j <= r-1; j++) {
                if (arr[j] < x) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[i+1], arr[r]);

            return i+1;
        }

};

int main(int argc, char* argv[]) {

     vector<int> arr = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 2, 3, 2, 6, 5, 7, 9};

     Solution sol;
     sol.quick_sort(arr);

     for (auto iter = arr.begin(); iter < arr.end(); iter++) {
         cout << *iter << " ";
     }
     cout << endl;

    return 0;
}
