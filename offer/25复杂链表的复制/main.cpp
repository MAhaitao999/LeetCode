/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Thu 18 Jun 2020 10:27:58 PM CST
 ************************************************************************/
// 题目描述
// 输入一个复杂链表(每个节点中有节点值, 以及两个指针, 一个指向下一个节点, 
// 另一个特殊指针random指向一个随机节点), 请对此链表进行深拷贝, 并返回拷
// 贝后的头结点. (注意, 输出结果中请不要返回参数中的节点引用, 否则判断程序直接返回空)
#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next, *random;
    RandomListNode(int x): 
        label(x), next(NULL), random(NULL) {
            ;
        }
};

// 方法1: 
class Solution1 {
    public:
        RandomListNode* clone(RandomListNode* pHead) {
            // cout << "1111" << endl;
            if (NULL == pHead) {
                return NULL;
            } 
            RandomListNode* p1 = pHead;

            // 第一步: A->B->C->D->NULL ----> A->A'->B->B'->C->C'->D->D'->NULL
            while (NULL != p1) {
                RandomListNode* tmp = new RandomListNode(p1->label);
                tmp->next = p1->next;
                p1->next = tmp;
                p1 = tmp->next;
            }
            // cout << "22222" << endl;

            // 第二步: 复制随机节点
            p1 = pHead;
            while (NULL != p1) {
                if (NULL == p1->random) { // 可省略的步骤, 因为初始化的时候random就已经初始化为NULL
                    p1->next->random = NULL;
                    p1 = p1->next->next;
                }
                else {
                    p1->next->random = p1->random->next;
                    p1 = p1->next->next;
                }
            }

            // cout << "333333333333" << endl;

            // 第三步: 断开A->A'->B->B'->C->C'->D->D'为A->B->C->D->NULL和A'->B'->C'->D'->NULL
            RandomListNode* pnewHead = pHead->next;
            RandomListNode* tmp1 = pnewHead;
            p1 = pHead;

            while (NULL != p1->next) {
                tmp1 = p1->next;
                p1->next = tmp1->next;
                p1 = tmp1;
                tmp1 = p1->next;
            }

            return pnewHead;
        }
};

// 方法2: 用一个hashmap建立新旧链表节点的对应的节点关系
// 迭代旧链表, 从而在hashmap中更新新链表的next与random两个字段
class Solution2 {
    public:
        RandomListNode* clone(RandomListNode* pHead) {

            // cout << "=================" << endl;
            if (NULL == pHead) {
                return NULL;
            }
            RandomListNode* pnewHead = new RandomListNode(pHead->label);
            RandomListNode* p = pHead;
            RandomListNode* q = pnewHead;

            while (NULL != p->next) {
                m[p] = q;
                // cout << "p=" << p << "; q=" << q << endl;
                q->next = new RandomListNode(p->next->label);
                p = p->next;
                q = q->next;
            }
            m[p] = q;

            p = pHead;
            q = pnewHead;
            while (NULL != q->next) {
                // cout << "p->random is: " << p->random << endl;
                // cout << "m[p->random] is: " << m[p->random] << endl;
                q->random = m[p->random];
                p = p->next;
                q = q->next;
            }

            q->random = m[p->random];

            return pnewHead;
        }

    private:
        map<RandomListNode*, RandomListNode*> m;

};

int main(int argc, char* argv[]) {

    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    RandomListNode n5(5);
    // RandomListNode n6(6);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    // n5.next = &n6;

    n1.random = &n3;
    n2.random = &n5;
    n3.random = NULL;
    n4.random = &n2;
    n5.random = NULL;
    // n6.random = &n3;

    // cout << "++++++++++++++++" << endl;
    Solution2 sol2;
    RandomListNode* pnewHead = sol2.clone(&n1);
    RandomListNode* p1 = pnewHead;
    while (p1) {
        cout << p1->label << " ";
        p1 = p1->next;
    }

    while (pnewHead) {
        if (NULL != pnewHead->random) {
            cout << pnewHead->random->label << " ";
        }
        else {
            cout << "#" << " ";
        }
        pnewHead = pnewHead->next;
    }

    cout << endl;

    return 0;
}
