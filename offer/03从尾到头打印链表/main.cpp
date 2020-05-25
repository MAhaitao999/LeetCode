#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} ListNode;

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

        ListNode* cur;
        cur = head;
        // cout << "cur is: " << cur->data << endl
        //      << (cur->next->next->next->next->next == NULL) << endl;
        stack<int> sta;
        while (cur->next != NULL) {
            // cout << "------------" << endl;
            sta.push(cur->data);
            cur = cur->next;
            // cout << (cur->next) << endl;
        }

        sta.push(cur->data);

        vector<int> printout;

        while (!sta.empty()) {
            printout.push_back(sta.top());
            sta.pop();
        }

        return printout;
        
    }
};

int main(int argc, char* argv[]) {

    ListNode ln1 = {1, NULL};
    ListNode ln2 = {2, NULL};
    ListNode ln3 = {3, NULL};
    ListNode ln4 = {4, NULL};
    ListNode ln5 = {5, NULL};

    ln4.next = &ln5;
    ln3.next = &ln4;
    ln2.next = &ln3;
    ln1.next = &ln2;

    Solution sol;
    vector<int> res = sol.printListFromTailToHead(&ln1);
    for (auto iter=res.begin(); iter < res.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}


