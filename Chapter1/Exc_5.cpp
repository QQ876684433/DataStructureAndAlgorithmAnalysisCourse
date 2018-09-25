//
// Created by steve on 18-9-4.
//

#include <iostream>

using namespace std;

bool is_word_palindrome(string word, int start, int end) {
    if (word.empty() || word.length() == 1) return true;

    if (word[start] != word[end]) return false;
    if (start > end) return true;
    else {
        return is_word_palindrome(word, start + 1, end - 1);
    }
}

bool is_sentence_palindrome(string sentence, int start, int end) {
    if (sentence.empty() || (sentence.length()==1 && isalpha(sentence[0]))) return true;

    while (true) {
        if (!isalpha(sentence[start])) start++;
        else break;
    }
    while (true) {
        if (!isalpha(sentence[end])) end--;
        else break;
    }

    if (tolower(sentence[start]) != tolower(sentence[end])) return false;
    if (start < end) return true;
    else {
        start++;
//        while (true) {
//            if (!isalpha(sentence[start])) start++;
//            else break;
//        }
        end--;
//        while (true) {
//            if (!isalpha(sentence[end])) end--;
//            else break;
//        }

        return is_word_palindrome(sentence, start, end);
    }
}

int main() {
    string input;
    cin >> input;
    cout << is_word_palindrome(input, 0, input.length() - 1) << endl;
    getchar();
    getline(cin, input);
    cout << is_sentence_palindrome(input, 0, input.length() - 1) << endl;
    return 0;
}