#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
	ListNode(int x):
		val(x), next(NULL) {
		}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> arr;
        struct ListNode* p = head;
        while (p != NULL) {
            arr.push(p->val);
            p = p->next;
        }
        while (!arr.empty()) {
            result.push_back(arr.top());
            arr.pop();
        }
        return result;
    }  
};

int main(int argc, char* argv[]) {

    struct ListNode ln1(1);
    struct ListNode ln2(2);
    struct ListNode ln3(3);
    struct ListNode ln4(4);
    struct ListNode ln5(5);

	ln4.next = &ln5;
	ln3.next = &ln4;
	ln2.next = &ln3;
	ln1.next = &ln2;

    Solution sol;
	vector<int> res = sol.printListFromTailToHead(&ln1);
	for (auto iter = res.begin(); iter < res.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;

    return 0;
}


