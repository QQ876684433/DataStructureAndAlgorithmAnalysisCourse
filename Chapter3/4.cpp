//
// Created by steve on 18-9-25.
//

#include <iostream>

using namespace std;

void Josephus_in_array(int *arr, int n, int m) {
    int ptr = 0;
    int a = 0;
    int last_out;//标记最后一个出列的数
    while (a < n) {
        int b = m;
        while (b) {
            if (arr[ptr % n] >= 1) {
                b--;
            }
            ptr++;
        }
        last_out = arr[(ptr-1)%n];
        arr[(ptr-1) % n] = 0;//标记已经出列
        a++;//标记有多少人出列
    }
    cout << last_out << endl;
}

int main() {
    int arr[531] ;
    for (int i = 1; i <= 531; ++i) {
        arr[i-1] = i;
    }
    Josephus_in_array(arr,531,27);
    return 0;
}