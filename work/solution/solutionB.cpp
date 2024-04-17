#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        std::string prefix = std::to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            while (nums[i] < std::stoi(prefix) || !std::to_string(nums[i]).substr(0, prefix.size()).compare(0, prefix.size(), prefix)) {
                prefix.pop_back();
                if (prefix.empty()) return 0;
            }
        }
        return std::stoi(prefix);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1000, 1024, 1055};
    int result = solution.longestCommonPrefix(nums);
    std::cout << "Longest common prefix: " << result << std::endl;
    return 0;
}