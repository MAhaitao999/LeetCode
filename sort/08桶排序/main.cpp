/*************************************************************************
    > File Name: main.cpp
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Tue 21 Jul 2020 07:22:19 AM CST
 ************************************************************************/
// 桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
// 为了使桶排序更加高效，我们需要做到这两点：
// 1. 在额外空间充足的情况下, 尽量增大桶的数量
// 2. 使用的映射函数能够将输入的N个数据均匀地分配到K个桶中
// 同时, 对于桶中元素的排序, 选择何种比较排序算法对于性能的影响至关重要.

// 问题:
// 1. 什么时候最快
// 当输入的数据可以均匀地分配到每一个桶中.
// 2. 什么时候最慢
// 当输入地数据被分配到同一个桶中.
// 3. 
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
const int BUCKET_NUM = 10;

struct ListNode {
    explicit ListNode(int i = 0):mData(i), mNext(NULL) {}
    ListNode* mNext;
    int mData;
};

ListNode* insert(ListNode* head, int val) {
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre, *curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;

    while (NULL != curr && curr->mData <= val) {
        pre = curr;
        curr = curr->mNext;
    }

    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}

ListNode* Merge(ListNode *head1,ListNode *head2){
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while(NULL!=head1 && NULL!=head2){
        if(head1->mData <= head2->mData) {
            dummy->mNext = head1;
            head1 = head1->mNext;
        }else {
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
            dummy = dummy->mNext;
    }
    if(NULL!=head1) dummy->mNext = head1;
    if(NULL!=head2) dummy->mNext = head2;
       
    return dummyNode.mNext;
}

void BucketSort(int n, int arr[]) {
    vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
    for (int i = 0; i < n; i++) {
        int index = arr[i]/BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head,arr[i]);
    }
    ListNode *head = buckets.at(0);
    for (int i = 1; i < BUCKET_NUM; ++i) {
        head = Merge(head, buckets.at(i));
    }

    for (int i = 0; i < n; i++) {
        arr[i] = head->mData;
        head = head->mNext;
    }
}

int main(int argc, char* argv[]) {

    int arr[] = {3, 1, 5, 23, 28, 10, 19, 54, 29, 12};
    BucketSort(10, arr);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
