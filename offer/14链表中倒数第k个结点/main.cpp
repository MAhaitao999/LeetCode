/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 03 Jun 2020 12:36:04 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 方法一: 先遍历一遍求出链表的长度n, 然后计算倒数第k个是正数的第n-k个,
// 然后再顺序遍历到第n-k. 时间复杂度为O(2n-k)
class Solution1 {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		
		if (!pListHead || k <= 0) {
		    return NULL;
		}

        int length = 0;
		ListNode* curNode = pListHead;
		while (curNode) {
		    length++;
			curNode = curNode->next;
		}
		// cout << "The length of List is: " << length << endl;

		int pos = length - k;
		// cout << "The find pos is: " << pos << endl;

		if (pos < 0) {
		    return NULL;
		}

		else {
			curNode = pListHead;
		    while (pos > 0) {
			    curNode = curNode->next;
				pos--;
			}
			cout << "The find value is: " << curNode->val << endl;
			return curNode;
		}
    }
};

// 方法二: 快慢指针, 首先让快指针先行k步, 然后让快慢指针每次同行一步, 直到
// 快指针指向空节点, 慢指针就是倒数第k个节点.
class Solution2 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	    if (!pListHead || k <= 0) {
		    return NULL;
		}
		ListNode* slow = pListHead;
		ListNode* fast = pListHead;

		while (k--) {
		    if (fast != NULL) {
			    fast = fast->next;
			}
			else {
			    return NULL; // 如果单链表长度 < k, 直接返回.
			}
		}

		while (fast != NULL) {
		    slow = slow->next;
			fast = fast->next;
		}

		cout << "The find val is: " << slow->val << endl;
		return slow;
	}
};

int main(int argc, char* argv[]) {
	
	ListNode n0 = {0};
	ListNode n1 = {1};
	ListNode n2 = {2};
	ListNode n3 = {3};
	ListNode n4 = {4};
	ListNode n5 = {5};
	ListNode n6 = {6};
	ListNode n7 = {7};

	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	Solution1 sol1;
	ListNode* p1 = sol1.FindKthToTail(&n0, 6);

	Solution2 sol2;
	ListNode* p2 = sol2.FindKthToTail(&n0, 6);


    return 0;
}
