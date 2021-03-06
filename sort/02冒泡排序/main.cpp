/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Mon Jul 13 11:22:38 2020
 ************************************************************************/
// 冒泡排序(Bubble Sort)也是一种简单直观的排序算法. 它重复地走访过要排序的数列, 
// 一次比较两个元素, 如果他们的顺序错误就把他们交换过来.走访数列的工作是重复地
// 进行直到没有再需要交换, 也就是说该数列已经排序完成. 这个算法的名字由来是因为
// 越小的元素会经由交换慢慢"浮"到数列的顶端.
// 作为最简单的排序算法之一, 冒泡排序给我的感觉就像Abandon在单词书里出现的感觉一样, 
// 每次都在第一页第一位, 所以最熟悉. 冒泡排序还有一种优化算法, 就是立一个flag, 
// 当在一趟序列遍历中元素没有发生交换, 则证明该序列已经有序. 
// 但这种改进对于提升性能来说并没有什么太大作用.

// 算法步骤
// 比较相邻的元素. 如果第一个比第二个大, 就交换他们两个.
// 对每一对相邻元素作同样的工作, 从开始第一对到结尾的最后一对. 这步做完后, 最后的元素会是最大的数.
// 针对所有的元素重复以上的步骤, 除了最后一个.
// 持续每次对越来越少的元素重复上面的步骤, 直到没有任何一对数字需要比较.

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        void bubble_sort(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr.size()-1-i; j++) {
                    if (arr[j] > arr[j+1]) {
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
       }
};

int main(int argc, char* argv[]) {

    vector<int> arr = {1, 9, 9, 2, 1, 1, 2, 3, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    Solution sol;
    sol.bubble_sort(arr);

    for (auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
