/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed 03 Jun 2020 11:30:31 PM CST
 ************************************************************************/
// 参考: https://www.jianshu.com/p/f7534f8d7bf2

#include <iostream>
using namespace std;

struct ListNode {
    int val;
	struct ListNode* next;
	ListNode(int x) : 
		val(x), next(NULL){
	}
};

// 方法1: 迭代法
// 迭代法从前往后遍历链表, 定义三个指针分别指向相邻的三个结点, 反转前两个结点,
// 即让第二个结点指向第一个结点. 然后依次往后移动指针, 直到第二个结点为空结束,
// 再处理链表头尾即可.
class Solution1 {
public:
	ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) { // 空链或者只有一个节点, 直接返回头指针
		    return pHead;
		}
		else { // 至少有两个节点
		    ListNode* p1 = pHead;    // 第一个节点
			ListNode* p2 = p1->next; // 第二个节点
			ListNode* p3 = p2->next; // 第三个节点

		    while (p2 != NULL) {
		        p3 = p2->next;
                p2->next = p1;  // 第二个结点指向第一个结点，进行反转
			    p1 = p2;        // 第一个结点往后移
			    p2 = p3;        // 第二个结点往后移
		    }

		    pHead->next = NULL;
		    pHead = p1;
		    return pHead;
	    }
	}
};

// 方法2: 递归法
// 基线条件: 空链或只有一个结点, 直接返回头指针
// 递归条件: 递归调用, 返回子链表反转后的头指针
class Solution2 {
public:
	ListNode* ReverseList(ListNode* pHead) {
	    if (pHead == NULL || pHead->next == NULL) { // 空链或只有一个结点, 直接返回头指针
		    return pHead;
		}
		else { // 有两个以上结点
		    ListNode * new_head = ReverseList(pHead->next);
			pHead->next->next = pHead;
			pHead->next = NULL;

			return new_head;
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

	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;
	ln5.next = &ln6;
	ln6.next = &ln7;

	ListNode* pHead = &ln1;

	Solution2 sol2;
	sol2.ReverseList(pHead);



    return 0;
}
