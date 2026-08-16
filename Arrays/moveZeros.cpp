/*283. Move Zeros 

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
        }
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

    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    cout << "Test 1: ";
    printVector(nums1);

    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    cout << "Test 2: ";
    printVector(nums2);

    vector<int> nums3 = {1, 0, 0, 2, 0, 3};
    solution.moveZeroes(nums3);
    cout << "Test 3: ";
    printVector(nums3);

    return 0;
}