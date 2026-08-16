/*1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];

        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> result1 = solution.twoSum(nums1, 9);
    cout << "Test 1: ";
    printVector(result1);

    vector<int> nums2 = {3, 2, 4};
    vector<int> result2 = solution.twoSum(nums2, 6);
    cout << "Test 2: ";
    printVector(result2);

    vector<int> nums3 = {3, 3};
    vector<int> result3 = solution.twoSum(nums3, 6);
    cout << "Test 3: ";
    printVector(result3);

    return 0;
}