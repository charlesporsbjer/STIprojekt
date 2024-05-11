#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isValid(string s) {
    unordered_set<int> clearedIndexes;
    char current;
    bool legalFlag;
    for (int i = 0; i < s.length(); i++) {
        current = s[i];
        legalFlag = 0;
        if (current == ')') {
            for (int j = i -1; legalFlag != 1 && j >= 0; j--) {
                if (clearedIndexes.find(j) == clearedIndexes.end()) {
                    if (s[j] == '(') {
                        clearedIndexes.insert(i);
                        clearedIndexes.insert(j);
                        legalFlag = 1;
                    }
                    else
                        return false;
                }
            }
        }
        else if (current == ']') {
            for (int j = i -1; legalFlag != 1 && j >= 0; j--) {
                if (clearedIndexes.find(j) == clearedIndexes.end()) {
                    if (s[j] == '[') {
                        clearedIndexes.insert(i);
                        clearedIndexes.insert(j);
                        legalFlag = 1;
                    }
                    else
                        return false;
                }
            }
        }
        else if (current == '}') {
            for (int j = i -1; legalFlag != 1 && j >= 0; j--) {
                if (clearedIndexes.find(j) == clearedIndexes.end()) {
                    if (s[j] == '{') {
                        clearedIndexes.insert(i);
                        clearedIndexes.insert(j);
                        legalFlag = 1;
                    }
                    else
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    string validString = {'{', '}', '(', ')'};
    string invalidString = {'(', '(', ']'};

    cout << isValid(validString) << endl;
    cout << isValid(invalidString) << endl;

    return 0;
}