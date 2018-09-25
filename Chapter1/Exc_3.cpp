//
// Created by steve on 18-9-4.
//

#include <iostream>

using namespace std;

int get_max(int *num, int len, int cur) {
    if (cur == len - 1) return num[cur];
    else {
        int temp = get_max(num, len, cur + 1);
        return num[cur] < temp ? temp : num[cur];
    }
}

float get_average(int *num, int len, int cur) {
    if (cur == len - 1) return num[cur];
    else {
        float average = get_average(num, len, cur + 1);
        return (num[cur] + average * (len - cur - 1)) / (len - cur);
    }
}

int main() {
    int num[] = {2, 3, 6, 4, 8, 9, 5};
    cout << get_max(num, 7, 0);
    cout << endl;
    cout << get_average(num, 7, 0);
    return 0;
}