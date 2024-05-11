#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool wordBreak(string A, vector<string> &B) {
    unordered_set<string> wordDict(B.begin(), B.end());
    int n = A.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.find(A.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    int n = 12;
    vector<string> B = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    string A = "mango";

    if (wordBreak(A, B)) {
        cout << "1\n"; // String can be segmented
    } else {
        cout << "0\n"; // String cannot be segmented
    }

    return 0;
}