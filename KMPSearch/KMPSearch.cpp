#include <iostream>
#include <string>

using namespace std;

// Function to compute the prefix function for the pattern
int* computePrefixFunction(const string& pattern) {
    int n = pattern.size();
    int* pi = new int[n];
    pi[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// KMP search function
void kmpSearch(const string& text, const string& pattern, int* prefixFunction) {
    int n = pattern.size();
    int m = text.size();
    int i = 0, j = 0;
    while (i < m) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = prefixFunction[j - 1];
            } else {
                i++;
            }
        }
        if (j == n) {
            cout << "Pattern occurs at index: " << i - n << endl;
            j = prefixFunction[j - 1];
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    int* prefixFunction = computePrefixFunction(pattern);
    kmpSearch(text, pattern, prefixFunction);
    
    return 0;
}