/*628. Maximum Product of Three Numbers

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

Constraints:
3 <= nums.length <= 104
-1000 <= nums[i] <= 1000*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }

        return max(min1 * min2 * max1,
                   max1 * max2 * max3);
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1: "
         << solution.maximumProduct(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test 2: "
         << solution.maximumProduct(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {-1, -2, -3};
    cout << "Test 3: "
         << solution.maximumProduct(nums3) << endl;

    // Extra useful test case
    vector<int> nums4 = {-10, -10, 1, 2, 3};
    cout << "Test 4: "
         << solution.maximumProduct(nums4) << endl;

    return 0;
}