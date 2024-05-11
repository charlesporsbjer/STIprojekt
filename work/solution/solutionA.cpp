#include <iostream>
#include <vector>
#include <string>

int longestCommonPrefix(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::string strNums = std::to_string(nums[0]);
    std::string prefix = "";
    int jNum = 0;
    while (true) {
        if (jNum >= strNums.size()) 
            return std::stoi(prefix);
        char currentChar = strNums[jNum];
        for (const int num : nums) {
            std::string strNum = std::to_string(num);
            if (jNum >= strNum.size() || strNum[jNum] != currentChar) {
                return std::stoi(prefix);
            }
        }
        prefix += currentChar;
        jNum++;
    }
    return std::stoi(prefix);  
}

int main() {
    std::vector<int> nums = {1000, 1024, 1055};
    int result = longestCommonPrefix(nums);
    std::cout << "Longest common prefix: " << result << std::endl;
    return 0;
}