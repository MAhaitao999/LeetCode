/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 27 May 2020 09:30:45 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// 把一个数组最开始的若干个元素搬到数组的末尾, 我们称之为数组的旋转.
// 输入一个非递减排序的数组的一个旋转, 输出旋转数组的最小元素.
// 例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转, 该数组的最小值为1.
// NOTE: 给出的所有元素都大于0, 若数组大小为0, 请返回0.
// {5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 4}
// {8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7}

class Solution1 {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
			if (rotateArray.size() == 0) {
				cout << "rotateArray is empty!" << endl;
			    return 0;
			}
            int min = rotateArray[0];
			for (int i = 0; i < rotateArray.size(); i++) {
			    if (rotateArray[i] < min) {
				    min = rotateArray[i];
				}
			}
			return min;
		}
};

// 稍微优化
class Solution2 {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            if (rotateArray.size() == 0) {
                cout << "rotateArray is empty!" << endl;
				return 0;
			}
			for (int i = 0; i < rotateArray.size() - 1; i++) {
			    if (rotateArray[i] > rotateArray[i + 1]) {
				    return rotateArray[i + 1];
				}
			}
			return rotateArray[0];
		}	
};

// 二分查找
class Solution3 {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            if (rotateArray.size() == 0) {
		        cout << "rotateArray is empty!" << endl;
				return 0;
			}
			int low = 0;
			int high = rotateArray.size() - 1;
			int mid = low + (high - low) / 2;
			while (low < high) {
				/*cout << "low is: " << low << " mid is: " << mid << " high is: " << high << endl;*/
			    // (1) 出现这种情况的rotateArray类似[3, 4, 5, 6, 0, 1, 2], 此时最小数字一定在mid右边
			    if (rotateArray[mid] > rotateArray[high]) {
                    low = mid + 1;
			    }
			    // (2) 出现这种情况的rotateArray类似[1, 0, 1, 1, 1]或者[1, 1, 1, 0, 1], 
			    // 此时最小数字不好判断在mid左边还是右边, 这时只好一个一个试.
			    else if (rotateArray[mid] == rotateArray[high]) {
			        high--;
			    }
			    // (3) 出现这种情况的rotateArray类似[7, 2, 3, 4, 5, 6, 6], 此时最小数字一定就是
			    // rotateArray[mid]或者在mid的左边,  因为右边必然都是递增的.
			    // 这里有一个坑: 如果待查询的范围最后只剩两个数, 那么mid一定会指向下标靠前的
				// 数字, 比如说rotateArray=[4, 6], rotateArray[low]=4; rotateArray[mid]=4;
				// rotateArray[high]=6; 如果high=mid-1, 就会产生错误, 因此high=mid.
				// 但情形(1)中low=mid+1就不会有错.
			    else {
			        high = mid;
			    }
				mid = low + (high - low) / 2;
			}
			/*cout << "-----" << low << endl;*/
			return rotateArray[low];
		}
};

int main(int argc, char* argv[]) {

    vector<int> rotateArray = {7, 7, 8, 9, 10, 2, 2, 3};
    Solution1 sol1;
	int res1 = sol1.minNumberInRotateArray(rotateArray);
	cout << res1 << endl;
	Solution2 sol2;
	int res2 = sol2.minNumberInRotateArray(rotateArray);
	cout << res2 << endl;
	Solution3 sol3;
	int res3 = sol3.minNumberInRotateArray(rotateArray);
	cout << res3 << endl;

    return 0;
}
