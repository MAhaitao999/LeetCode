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

// 感觉应该没问题, 但是牛客网没通过.
class Solution1 {
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

// 方法1: 迭代法
class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* vhead = new ListNode(-1);
		ListNode* cur = vhead;
		while (pHead1 && pHead2) {
		    if (pHead1->val <= pHead2->val) {
			    cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
			    cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		cur->next = pHead1 ? pHead1 : pHead2;
		return vhead->next;
	}
};

// 方法2: 迭代法
class Solution3 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		if (pHead1->val <= pHead2->val) {
		    pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else {
		    pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
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
	
	/*
    Solution1 sol1;
	ListNode* Head = sol1.Merge(p1, p2);
    */

	/*
	Solution2 sol2;
	ListNode* Head = sol2.Merge(p1, p2);
    */

	Solution3 sol3;
	ListNode* Head = sol3.Merge(p1, p2);

	while (Head) {
	    cout << Head->val << " ";
		Head = Head->next;
	}
	cout << endl;

    return 0;
}
