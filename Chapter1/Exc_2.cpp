//
// Created by steve on 18-9-4.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void permute(string str) {
        char s[str.length()];
        for (int i = 0; i < str.length(); ++i) {
            s[i] = str[i];
        }
        permute(s, 0, static_cast<int>(str.length() - 1));
    }

private:
    void permute(char *str, int low, int high) {
        if (low == high) {
            for (int i = 0; i <= high; ++i) {
                cout << str[i];
            }
            cout << endl;
        } else {
            for (int i = low; i <= high; ++i) {
                swap(str[low],str[i]);
                permute(str,low+1,high);
                swap(str[low],str[i]);
            }
        }
    }
};


int main() {
    string input;
    cin >> input;
    Solution solution;
    solution.permute(input);
    return 0;
}