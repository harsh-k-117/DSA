/*217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> s;

        for (int num : nums) {
            if(s.count(num)){
                return true;
            }
            s.insert(num);
        }

        return false;

    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << boolalpha << s.containsDuplicate(nums1) << endl; // Output: true    

    vector<int> nums2 = {1, 2, 3, 4};
    cout << boolalpha << s.containsDuplicate(nums2) << endl; // Output: false

    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};     
    cout << boolalpha << s.containsDuplicate(nums3) << endl; // Output: true

    return 0;
}