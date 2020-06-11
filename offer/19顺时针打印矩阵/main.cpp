/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 10 Jun 2020 01:31:28 AM CST
 ************************************************************************/
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵： 1   2  3  4 
//                              5   6  7  8 
//                              9  10 11 12 
//                              13 14 15 16 
// 则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res = {};
        int rows = matrix.size();
		int cols = matrix[0].size();
		if (rows == 0 && cols == 0) {
		    return res;
		}
		int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
		
		while (left <= right && top <= bottom) {
			if (left == right && top == bottom) {
			    res.push_back(matrix[left][top]);
				return res;
			}

			if (left == right && top < bottom) {
			    for (int i = top; i <= bottom; i++) {
				    res.push_back(matrix[i][left]);
				} 
				return res;
			}

			if (left < right && top == bottom) {
			    for (int i = left; i <= right; i++) {
				    res.push_back(matrix[top][i]);
				}
				return res;
			}
			// 从左到右
            for (int i = left; i < right; i++) {
				cout << "left->right: " << matrix[top][i] << " ";
			    res.push_back(matrix[top][i]);
			}

			// 从上到下
			for (int i = top; i < bottom; i++) {
				cout << "top->down: " << matrix[i][right] << " ";
			    res.push_back(matrix[i][right]);
			}

			// 从右到左
			for (int i = right; i > left; i--) {
				cout << "right->left: " << matrix[bottom][i] << " ";
			    res.push_back(matrix[bottom][i]);
			}

			// 从下到上
			for (int i = bottom; i > top; i--) {
				cout << "down->top: " << matrix[i][left] << " ";
			    res.push_back(matrix[i][left]);
			}
			left++, right--, top++, bottom--;
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
    // vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    // vector<vector<int> > matrix = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    // vector<vector<int> > matrix = {{1, 2}, {3, 4}};
	// vector<vector<int> > matrix = {{1}, {2}, {3}, {4}, {5}};
	vector<vector<int> > matrix = {{1, 2, 3, 4, 5, 6, 7, 8}};
	Solution sol;
	vector<int> a = sol.printMatrix(matrix);

	cout << endl;
	for (auto iter = a.begin(); iter < a.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;
    return 0;
}
