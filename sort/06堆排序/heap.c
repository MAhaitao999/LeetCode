/*************************************************************************
    > File Name: heap.c
    > Author: Henry Ma
    > Mail: iloveicRazavi@gmail.com 
    > Created Time: Wed Jul 15 10:06:02 2020
 ************************************************************************/
// 参考了B站Up主正月里打灯笼的"堆排序"视频
// Heap:
// 1. Complete Binary Tree
// 2. parent > children (大顶堆)

// 对于节点i
// parent = (i - 1) / 2
// c1 = 2i + 1
// c2 = 2i + 2

#include <stdio.h>
void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(int tree[], int n, int i) {

    if (i >= n) {
        return;
    }
    int c1 = 2 * i + 1; // 左孩子
    int c2 = 2 * i + 2; // 右孩子
    int max = i;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }

    // 交换i和max
    if (max != i) {
        swap(tree, i, max);
        heapify(tree, n, max); // 此递归一定不能省, 否则就不是堆了...
    }
}

void build_heap(int tree[], int n) {
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;

    for (int i = parent; i >= 0; i--) {
        heapify(tree, n, i);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n; i > 0; i--) {
        build_heap(arr, i);
        swap(arr, 0, i-1);
    }
}

int main(int argc, char* argv[]) {

    int tree[] = {1, 2, 3, 4, 7, 5, 3, 2, 0, 9, 2, 3, 8, 7, 4, 5, 8, 2, 1, 3, 0, 8};
    int n = sizeof(tree) / sizeof(tree[0]);

    heap_sort(tree, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");

    return 0;
}
