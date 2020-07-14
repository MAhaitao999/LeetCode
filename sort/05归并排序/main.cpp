/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue Jul 14 12:06:59 2020
 ************************************************************************/
// 归并排序
// 1. 将序列中待排序数字分为若干组, 每个数字分为一组.
// 2. 将若干个组两两合并, 保证合并后的组是有序的.
// 3. 重复第二步操作直到只剩下一组, 排序完成.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 递归版本
class Solution {
    public:
        void merge_sort(vector<int>& arr) {
            merge_sort_base(arr, 0, arr.size()-1);
        }

    private:
        void merge_sort_base(vector<int>& arr, int front, int end) {
            if (front >= end) {
                return;
            }

            int mid = (front + end) / 2;
            merge_sort_base(arr, front, mid);
            merge_sort_base(arr, mid+1, end);
            merge(arr, front, mid, end);
        }

        void merge(vector<int>& arr, int front, int mid, int end) {
            // preconditions:
            // arr[front...mid] is sorted
            // arr[mid+1...end] is sorted
            // copy arr[front...mid] to LeftSubArr
            // copy arr[mid+1...end] to RightSubArr
            vector<int> LeftSubArr(arr.begin()+front, arr.begin()+mid+1);
            vector<int> RightSubArr(arr.begin()+mid+1, arr.begin()+end+1);
            
            // 在LeftSubArray以及RightSubArray后面添加一个非常大的值
            // 以防止下面的归并过程中出现访问越界的现象.
            LeftSubArr.insert(LeftSubArr.end(), INT_MAX);
            RightSubArr.insert(RightSubArr.end(), INT_MAX);

            int idxLeft = 0, idxRight = 0;
            for (int i = front; i < end+1; i++) {
                if (LeftSubArr[idxLeft] < RightSubArr[idxRight]) {
                    arr[i] = LeftSubArr[idxLeft];
                    idxLeft++;
                }
                else {
                    arr[i] = RightSubArr[idxRight];
                    idxRight++;
                }
            }
        }
};

// 迭代法
class Solution2 {
    public:
        void merge_sort(vector<int>& arr) {
            int len = arr.size();
            vector<int> tmp(arr.size());
            for (int seg = 1; seg < len; seg += seg) {
                for (int start = 0; start < len; start += 2*seg) {
                    int low = start;
                    int mid = min(start + seg, len);
                    int high = min(start + 2*seg, len);
                    int k = low;
                    int start1 = low, end1 = mid;
                    int start2 = mid, end2 = high;
                    while (start1 < end1 && start2 < end2) {
                        tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
                    }
                    while (start1 < end1) {
                        tmp[k++] = arr[start1++];
                    }
                    while (start2 < end2) {
                        tmp[k++] = arr[start2++];
                    }
                }
                // copy tmp to arr 需要logn次拷贝, 如果数据量很大的话挺花费时间的
                for (int i = 0; i < arr.size(); i++) {
                    arr[i] = tmp[i];
                }
            }
        }
};

// 迭代法减少拷贝的写法
class Solution3 {
    public:
        void merge_sort(vector<int>& arr) {
            int len = arr.size();
            int* array = new int[len];
            for (int i = 0; i < len; i++) {
                array[i] = arr[i];
            }
            merge_sort_array(array, len);
            for (int i = 0; i < len; i++) {
                arr[i] = array[i];
            }
            delete[] array;
        }

    private:
        void merge_sort_array(int arr[], int len) {
            int* a = arr;
            int* b = new int[len];

            for (int seg = 1; seg < len; seg *= 2) {
                for (int begin = 0; begin < len; begin += 2 * seg) {
                    int low = begin;
                    int mid = min(low + seg, len);
                    int high = min(len, low + 2*seg);

                    int begin1 = low, end1 = mid;
                    int begin2 = mid, end2 = high;
                    int k = low;

                    while (begin1 < end1 && begin2 < end2) {
                        a[begin1] < a[begin2] ? b[k++] = a[begin1++] : b[k++] = a[begin2++];    
                    }

                    while (begin1 < end1) {
                        b[k++] = a[begin1++];
                    }

                    while (begin2 < end2) {
                        b[k++] = a[begin2++];
                    }
                }

                int* tmp = a; // a和b之间相互倒腾, 如果最后一次a指向arr, 则直接返回, 否则还需再把b倒腾到a中一次
                a = b;
                b = tmp;
            }

            if (a != arr) { // 说明最后排序好的数据在b中
                for (int i = 0; i < len; i++) {
                    arr[i] = b[i];
                }
            }

            delete[] b; // 最后记得释放b
        }
};

int main(int argc, char* argv[]) {

    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 7, 8, 2, 9, 6, 3};
    Solution3 sol;
    sol.merge_sort(arr);

    for (auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
