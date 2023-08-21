#include <iostream>
#include <string>
#include <vector>

using namespace std;

void shiftTable(string pattern, vector<int>& shift) {
    int m = pattern.length();
    for (int i = 0; i < 256; ++i) {
        shift[i] = m;
    }
    for (int i = 0; i < m - 1; ++i) {
        shift[pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> shift(256);

    shiftTable(pattern, shift);

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i += shift[text[i]];
        }
    }
    return -1;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    int result = horspoolSearch(text, pattern);
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
