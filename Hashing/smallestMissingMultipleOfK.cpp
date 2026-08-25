/*3718. Smallest Missing Multiple of K

Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
A multiple of k is any positive integer divisible by k.

Example 1:
Input: nums = [8,2,3,4,6], k = 2
Output: 10
Explanation:
The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Example 2:
Input: nums = [1,4,7,10,15], k = 5
Output: 5
Explanation:
The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100
*/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        int multiple = k;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % k == 0){
                s.insert(nums[i]);
            }
        }

        while (s.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    std::cout << "Output: " << solution.missingMultiple(nums1, k1) << std::endl; // Output: 10

    std::vector<int> nums2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    std::cout << "Output: " << solution.missingMultiple(nums2, k2) << std::endl; // Output: 5

    return 0;
}