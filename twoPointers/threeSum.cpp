/*15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans = {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
            }
        }

        return ans;
    }
};

void printVector(const vector<vector<int>>& nums) {
    cout << "[";

    for (int i = 0; i < nums.size(); i++) {
        cout << "[";

        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j];

            if (j < nums[i].size() - 1) {
                cout << ", ";
            }
        }

        cout << "]";

        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1: ";
    printVector(solution.threeSum(nums1));

    vector<int> nums2 = {0, 1, 1};
    cout << "Test 2: ";
    printVector(solution.threeSum(nums2));

    vector<int> nums3 = {0, 0, 0};
    cout << "Test 3: ";
    printVector(solution.threeSum(nums3));

    return 0;
}