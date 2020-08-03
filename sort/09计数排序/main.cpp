/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue 21 Jul 2020 07:27:04 AM CST
 ************************************************************************/
// 计数排序的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中. 作为
// 一种线性复杂度的排序, 计数排序要求输入的数据必须是有确定范围的整数.
// 1. 计数排序的特征
// 当输入的元素是n个0到k之间的整数时, 它的运行时间时O(n+k). 计数排序不是比较
// 排序, 排序的速度快于任何比较排序的算法.
// 由于用来计数的数组C的长度取决于待排序数组中数据的范围(等于待排序数组的最
// 大值与最小值的差加上1), 这使得计数排序对于数据范围很大的数组, 需要大量时间
// 和内存. 例如: 计数排序是用来排序0到100之间的数字的最好的算法，但是它不适合
// 按字母顺序排序人名. 但是，计数排序可以用在基数排序中的算法来排序数据范围很
// 大的数组.
// 通俗地理解，例如有 10 个年龄不同的人，统计出有 8 个人的年龄比 A 小, 那 A 的
// 年龄就排在第 9 位, 用这个方法可以得到其他每个人的位置, 也就排好了序. 当然，
// 年龄有重复时需要特殊处理(保证稳定性), 这就是为什么最后要反向填充目标数组，
// 以及将每个数字的统计减去 1 的原因.
// 算法的步骤如下:
// (1) 找到待排序的数组中最大和最小的元素
// (2) 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
// (3) 对所有的计数累加(从C中的第一个元素开始，每一项和前一项相加)
// (4) 反向填充目标数组: 将每个元素i放在新数组的第C(i)项, 每放一个元素就将C(i)减去1
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
    public:
        void count_sort(vector<int>& arr) {
            int len = arr.size();
            int max = INT_MIN;
            int min = INT_MAX;
            for (int i = 0; i < len; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }

                if (arr[i] < min) {
                    min = arr[i];
                }
            }

            int *count_arr = (int*) malloc(sizeof(int)*(max-min+1));
            int *sorted_arr = (int*) malloc(sizeof(int)*len);

            for (int i = 0; i < max-min+1; i++) {
                count_arr[i] = 0;
            }

            for (int i = 0; i < len; i++) {
                count_arr[arr[i]-min]++;
            }

            for (int i = 1; i < max-min+1; i++) {
                count_arr[i] += count_arr[i-1];
            }

            /*
            for (int i = 0; i < max-min+1; i++) {
                cout << count_arr[i] << " ";
            }
            cout << endl;
            */
            
            for (int j = len; j > 0; j--) {
                sorted_arr[--count_arr[arr[j-1]-min]] = arr[j-1];
            }

            for (int i = 0; i < len; i++) {
                arr[i] = sorted_arr[i];
            }

            free(count_arr);
            free(sorted_arr);
        }
    private:
        ;
};

int main(int argc, char* argv[]) {
    
    // vector<int> arr = {1, 2, 3, 4, 1, 3, 2, 4, 5, 6, 7, 9, 11};
    vector<int> arr = {1};

    cout << "origin arr is: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Solution sol;
    sol.count_sort(arr);
    
    cout << "after sort arr is: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
