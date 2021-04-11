#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 辅助函数，求数据的最大位数
int maxbit(int data[], int n) {
    int maxvalue = data[0];
    for (int i = 1; i < n; i++) {
        if (maxvalue < data[i]) {
            maxvalue = data[i];
        }
    }

    int d = 1;  // 位数
    int p = 10;
    while (maxvalue >= p) {
        maxvalue /= p;
        ++d;
    }
    return d;
    
}

void radixsort(int data[], int n) {
    int d = maxbit(data, n);
    int *temp = new int[n];
    int *count = new int[10];
    int i, j, k;

    int radix = 1;

    for (i = 0; i < d; i++) {  // 进行d次排序
        for (j = 0; j < 10; j++) {  // 每次分配前先清空计数器
            count[j] = 0;
        }
        for (j = 0; j < n; j++) {  // 遍历所有元素
            k = (data[j] / radix) % 10;  // 统计每个桶中的记录数
            count[k]++;
        }

        for (j = 1; j < 10; j++) {
            count[j] = count[j] + count[j - 1];  // 将temp中的位置依次分配给每个桶
        }

        for (j = n - 1; j >= 0; j--) {  // 倒着来, 将所有桶中记录依次收集到tmp中
            k = (data[j] / radix) % 10;
            temp[count[k] - 1] = data[j];
            count[k]--;
        }

        for (j = 0; j < n; j++) {  // 将临时数组的内容复制到data中
            data[j] = temp[j];
        }
        radix = radix * 10;
    }
    delete [] temp;
    delete [] count;
}


int main(int argc, char *argv[]) {

    int data[] = {19, 39};
    int n = sizeof(data) / sizeof(int);
    cout << "现在有" << n << "个数" << endl;

    cout << "before radix sort: " << endl; 
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    radixsort(data, n);

    cout << "after radix sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}
