/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Sun 12 Jul 2020 04:28:24 PM CST
 ************************************************************************/
// 选择排序是一直简单直观的排序算法, 无论什么数据进去都是O(n^2)的时间复杂度, 
// 所以用到它的时候, 数据规模越小越好, 唯一的好处可能就是不占用额外的内存空间了吧.

// 1. 算法步骤:
// 首先在末排序序列中找到最小(大)元素, 存放到排序序列的起始位置.
// 再从剩余未排序元素中继续寻找最小(大)元素, 然后放到已排序序列的末尾.
// 重复第二步, 直到所有元素均排序完毕.
#include <iostream>
#include <vector>
#include <climits>
#include <typeinfo>

using namespace std;

class Solution {
    
    public:
        void select_sort(vector<int>& arr) {
            
            int pos_min = -1;
            if (0 == arr.size() || 1 == arr.size()) {
                return;
            }
            for (int i = 0; i < arr.size() - 1; i++) {
                
                pos_min = i;
                for(int j = i + 1; j < arr.size(); j++) {
                    
                    if (arr[pos_min] > arr[j]) {
                        pos_min = j;
                    }
                }
                
                swap(&arr[i], &arr[pos_min]);
            }
        }

    private:
        void swap(int* a, int *b) {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }

};


template <typename T>
void selection_sort(std::vector<T>& arr) {

    if (0 == arr.size()) {
        return;
    }
    cout << arr.size() - 1 << endl;
    cout << typeid(arr.size()).name() << endl; // arr.size()'s type is unsigned long
    for (int i = 0; i < arr.size() - 1; i++) { // C++中for循环的初始值会检查是否满足循环条件, when arr.size()=1, won't enter, when arr.size()=0, will enter.
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    } 
}


int main(int argc, char* argv[]) {

    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 7, 8, 9, 4, 2, 9, 3, 7, 1, 5, 23, 34, 19, 45, 23, 45, 34, 8, 3, 4, 7, 1, 9, 4, 9, 1, 98, 7, 23, 10, 19, 78, 91, 23, 47, 82};
    Solution sol;
    sol.select_sort(arr);
    selection_sort(arr);

    for (auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl; 

    return 0;
}
