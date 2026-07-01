/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }

};

/* int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
} */