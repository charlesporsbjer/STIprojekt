#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = "";
        int iVec = 0;
        int jChar = 0;
        while (true) {
            if (jChar >= strs[0].size()) 
                return prefix;
            char currentChar = strs[0][jChar];
            for (iVec = 0; iVec < strs.size(); iVec++) {
                if (jChar >= strs[iVec].size() || strs[iVec][jChar] != currentChar) {
                    return prefix;
                }
            }
            prefix += currentChar;
            jChar++;
        }
        return prefix;  
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    
    cout << Solution::longestCommonPrefix(strs);

    return 0;
}