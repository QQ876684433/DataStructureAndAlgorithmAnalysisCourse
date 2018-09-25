//
// Created by steve on 18-9-4.
//


/**
 * 找出从自然数 1, 2, …, n 中任取r个数的所有组合, 编一个递归算法.
     例子:  n = 5     1  2  3  4  5
                r = 3                 5  4  3
                                      5  4  2
                                      5  4  1
                                      5  3  2
                                      5  3  1
                                      5  2  1
                                      4  3  2
                                      4  3  1
                                      4  2  1
                                      3  2  1

 */

#include <iostream>

void Perm(int *num, int p, int r, int n, int cur);

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    int num[n];
    for (int i = 0; i < n; ++i) {
        num[i] = i + 1;
    }
    Perm(num, 0, r, n, 0);
    return 0;
}

/**
 *
 * @param num 所有数据,当找到一个组合时，0～r-1的数就是结果
 * @param p 计数，当p==r时说明已经找到一个组合
 * @param r 任取的r个数
 * @param n 数据的个数
 * @param cur 指针
 */
void Perm(int *num, int p, int r, int n, int cur) {
    if (p == r) {//找到一个组合
        for (int i = 0; i < r; ++i) {
            cout << num[i];
        }
        cout << endl;
    }
    for (int i = cur; i < n; ++i) {
        if (i + r - p > n) break;//判断是否越界
        swap(num[p], num[i]);
        Perm(num, p + 1, r, n, i + 1);
        swap(num[p], num[i]);
    }
}