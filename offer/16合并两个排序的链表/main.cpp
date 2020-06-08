/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 04 Jun 2020 11:58:05 PM CST
 ************************************************************************/
// 输入两个单调递增的链表, 输出两个链表合成后的链表, 当然我们需要合成后的链表满足单调不减规则.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
	struct ListNode* next;
	ListNode(int x):
		val(x), next(NULL) {
		    ;
		}
};

class Solution {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		    if (!pHead1) {
			    return pHead2;
			}

			if (!pHead2) {
			    return pHead1;
			}
			ListNode* pNewHead;
			ListNode* cur;

			if (pHead1->val < pHead2->val) {
			    pNewHead = pHead1;
				cur = pHead1;
				pHead1 = pHead1->next;
			}

			else {
			    pNewHead = pHead2;
				cur = pHead1;
				pHead2 = pHead2->next;
			}

			while (pHead1 != NULL && pHead2 != NULL) {
			    if (pHead1->val > pHead2->val) {
				    cur->next = pHead2;
					cur = cur->next;
					pHead2 = pHead2->next;
				}
				else {
				    cur->next = pHead1;
					cur = cur->next;
					pHead1 = pHead1->next;
				}
			}

			if (pHead1 == NULL) {
			    cur->next = pHead2;
			}
			else {
			    cur->next = pHead1;
			}

			return pNewHead;
		}
};
int main(int argc, char* argv[]) {

    ListNode ln1(1);
	ListNode ln2(2);
	ListNode ln3(3);
	ListNode ln4(4);
	ListNode ln5(5);
	ListNode ln6(6);
	ListNode ln7(7);
	ListNode ln8(8);
	ListNode ln9(9);
	ListNode ln10(10);
	ListNode ln11(11);
	ListNode ln12(12);

	ListNode* p1 = &ln1;
	ListNode* p2 = &ln2;

	ln1.next = &ln3;
	ln3.next = &ln5;
	ln5.next = &ln7;
	ln7.next = &ln9;
	ln9.next = &ln11;

	ln2.next = &ln4;
	ln4.next = &ln6;
	ln6.next = &ln8;
	ln8.next = &ln10;
	ln10.next = &ln12;

	ln11.next = NULL;
	ln12.next = NULL;
	
    Solution sol;
	ListNode* Head = sol.Merge(p1, p2);

	while (Head) {
	    cout << Head->val << " ";
		Head = Head->next;
	}
	cout << endl;

    return 0;
}
