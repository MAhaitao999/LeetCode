/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 20 May 2020 10:41:29 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#define M 20000
#define N 10000

using namespace std;

// 暴力搜索法, 时间复杂度为O(MN)

class Solution1 {
public:

    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[0].size(); j++) {
                if (target == array[i][j]) {
                    return true;
                } else {
                    continue;
                }
            }
        }
        return false;
    }
};

// 每一行进行二分法搜索, 时间复杂度为O(Mlog(N))

class Solution2 {
public:

    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); i++) {
            // bool res = BinSearch(array[i], target);
            int res = binary_search(array[i].begin(), array[i].end(), target);
            // cout << "第" << i << "行" << "二分查找的结果是: " << res << endl;
            if (res == 0) // 没找到
                continue;
            else // 找到了
                return true;
        }
        return false;
    }
};

// 每次选右上角或者左下角的数字, 以右上角为例: 如果target小于该数字, 则根据二维矩阵的特征, target
// 将小于该数字所在列的所有数字, 因此可以将这一列全部去掉. 如果target大于该数字, 则根据二维矩阵的特
// 征, target将大于该数字所在行的所有数字, 因此可以将这一列全部去掉.
// 时间复杂度为O(M + N)

class Solution3 {
public:

    bool Find(int target, vector<vector<int> > array) {
        int row = 0;
        int col = array[0].size() - 1;
        // cout << array[row][col-1] << endl;
        while (row <= array.size() - 1 && col >= 0) {
            // cout << "array[" << row << "]" << "[" << col << "]" << endl;
            if (target == array[row][col]) {
                return true;
            } else if (target < array[row][col]) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {

    // 定义二维矩阵
    vector<vector<int> > matrix(M);
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].resize(N);
    }

    // cout << matrix.size() << endl;
    // cout << matrix[0].size() << endl;

    // 初始化二维矩阵
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = i + j + 2;
        }
    }

    // 打印二维矩阵
    /*
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                    cout << setw(4) << matrix[i][j] << "  ";
                }
                cout << endl;
        }
     */

    vector<vector<int> > array(4);
    array[0] = {1, 2, 8, 9};
    array[1] = {2, 4, 9, 12};
    array[2] = {4, 7, 10, 13};
    array[3] = {6, 8, 11, 15};

    // 查找目标元素
    int target = 30002;
    Solution1 soul1;
    Solution2 soul2;
    Solution3 soul3;
    auto start = Clock::now();
    bool result1 = soul1.Find(target, matrix);
    auto end = Clock::now();
    cout << "方法1花费了"
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " microseconds" << std::endl;

    start = Clock::now();
    bool result2 = soul2.Find(target, matrix);
    end = Clock::now();
    cout << "方法2花费了"
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " microseconds" << std::endl;

    start = Clock::now();
    bool result3 = soul3.Find(target, matrix);
    end = Clock::now();
    cout << "方法3花费了"
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
            << " microseconds" << std::endl;

    cout << "result1 is: " << result1 << endl;
    cout << "result2 is: " << result2 << endl;
    cout << "result3 is: " << result3 << endl;

    return 0;
}
