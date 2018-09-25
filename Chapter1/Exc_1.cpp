//
// Created by steve on 18-9-4.
//

#include <iostream>

using namespace std;

int result = 0;

void solve(int n);

int main() {
    int n;
    cin >> n;
    result = 0;
    solve(n);
    cout << result << endl;
    return 0;
}

void solve(int n) {
    if (n) {
        if (n & 1) result++;
        solve(n >> 1);
    }
}