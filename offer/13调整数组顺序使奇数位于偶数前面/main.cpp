/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue Jun  2 09:53:26 2020
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 方法1: 使用栈
class Solution1 {
    public:
        void reOrderArray(vector<int> &array) {
            cout << array.size() << endl;
			stack<int> odd;
			stack<int> even;
			if (array.size() == 0) {
			    return;
			}
			else {
			    for (auto iter = array.rbegin(); iter != array.rend(); iter++) {
				    if (*iter % 2 == 1) { // 如果为奇数
					    odd.push(*iter);
					}
					else { // 如果为偶数
					    even.push(*iter);
					}
				}
				cout << "even number is: " << even.size() << endl;
				cout << "odd number is: " << odd.size() << endl;
			}

			auto iter2 = array.begin();
			while (!odd.empty()) {
			    *iter2 = odd.top();
				odd.pop();
				iter2++;
			}

			while (!even.empty()) {
			    *iter2 = even.top();
				even.pop();
				iter2++;
			}
		}
};

// 方法2: 使用两个数组分别存放奇数和偶数
class Solution2 {
public:
	void reOrderArray(vector<int> &array) {
	    vector<int> array1, array2;
		int m = 0, n = 0;
		for (int i = 0; i < array.size(); i++) {
		    if (array[i] % 2 == 1) { // 奇数
			    array1.push_back(array[i]);
				m++;
			}
			else { // 偶数
			    array2.push_back(array[i]);
				n++;
			}
		}
		array2.insert(array2.begin(), array1.begin(), array1.end());
		array = array2;
	}
};

// 方法3: 参考冒泡排序的思想: 让偶数不断向右边移动, 而冒泡的过程本身也
// 可以保证相对顺序的不变, 最后所有的偶数都移动到了右边, 最坏情况下外层循环需要进行array.size()次.
class Solution3 {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0) {
		    return;
		}
	    int loop = array.size() - 1;
		int count = 0;
		while (loop >= 0) {
		    if (array[loop] % 2 == 0) { // 如果为偶数
				count++;
			    int j = loop;
				while (j < array.size() - count) {
				    swap(array, j, j+1);
					j++;
				}
				loop--;
			}
			else {
			    loop--;
			}
		}
	}
private:

	void swap(vector<int>& array, int i, int j) {
	    auto temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
};

int main(int argc, char* argv[]) {
    
    // vector<int> array = {1, 2, 4, 32, 43, 21, 35, 65, 54, 37, 78, 21, 19};
    vector<int> array = {2, 4, 6, 1, 3, 5, 7};
	cout << "The origin array is: " << endl;
	for (auto iter = array.begin(); iter < array.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;
    // Solution1 sol1;
	// sol1.reOrderArray(array);

	// Solution2 sol2;
	// sol2.reOrderArray(array);

	Solution3 sol3;
	sol3.reOrderArray(array);
    
	cout << "After sort the array is: " << endl;
	for (auto iter = array.begin(); iter < array.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;
	
    return 0;
}
