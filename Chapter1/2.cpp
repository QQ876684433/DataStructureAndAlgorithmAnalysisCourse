//
// Created by steve on 18-9-4.
//

#include <iostream>

void solve(int n, char from, char to, char temp);

using namespace std;

int times;

int main() {
    int n;
    cin >> n;
    times = 0;
    solve(n, 'A', 'B', 'C');
    cout << times << " times in total." << endl;
    return 0;
}

/**
 * 如果n==1说明可以直接把它移动到目标位置
 *
 * @param n 要移动的盘子数
 * @param from 盘子所在的位置
 * @param to 盘子要移动的目标位置
 * @param temp 把n-1个盘子暂时移到的位置
 */
void solve(int n, char from, char to, char temp) {
    times++;
    if (n == 1) cout << from << " to " << to << endl;
    else {
        solve(n - 1, temp, from, to);
        cout << from << " to " << to << endl;
        solve(n - 1, temp, to, from);
    }
}