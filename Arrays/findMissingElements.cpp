/*3731. Find Missing Elements

You are given an integer array nums consisting of unique integers.
Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
The smallest and largest integers of the original range are still present in nums.
Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

Example 1:
Input: nums = [1,4,2,5]
Output: [3]
Explanation:
The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

Example 2:
Input: nums = [7,8,6,9]
Output: []
Explanation:
The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

Example 3:
Input: nums = [5,1]
Output: [2,3,4]
Explanation:
The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

Constraints:
2 <= nums.length <= 100
1 <= nums[i] <= 100 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> ans;
        int n = nums.size();
        int minimum = nums[0];
        int maximum = nums[0];

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);

            if (nums[i] > maximum) {
                maximum = nums[i];
            }
            else if (nums[i] < minimum) {
                minimum = nums[i];
            }
        }

        for (int i = minimum; i <= maximum; i++) {
            if (s.count(i) == 0) {
                ans.push_back(i);
            }
        }

        return ans;
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

    // Test Case 1
    vector<int> nums1 = {1, 4, 2, 5};
    vector<int> result1 = solution.findMissingElements(nums1);

    cout << "Test 1: ";
    printVector(result1);

    // Test Case 2
    vector<int> nums2 = {7, 8, 6, 9};
    vector<int> result2 = solution.findMissingElements(nums2);

    cout << "Test 2: ";
    printVector(result2);

    // Test Case 3
    vector<int> nums3 = {5, 1};
    vector<int> result3 = solution.findMissingElements(nums3);

    cout << "Test 3: ";
    printVector(result3);

    return 0;
}