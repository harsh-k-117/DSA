/*349. Intersection of Two Arrays 

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        unordered_set<int> ans;
        vector<int> result;

        for(int i=0; i<nums1.size(); i++){
            s.insert(nums1[i]);
        }

        for(int i=0; i<nums2.size(); i++){
            if(s.count(nums2[i]) && !ans.count(nums2[i])){      //exists in s and does not exist in ans -> add to ans
                ans.insert(nums2[i]);
            }
        }

        for(int num : ans){     //store the answer int vector form 
            result.push_back(num);
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result1 = solution.intersection(nums1, nums2);
    cout << "Test 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    vector<int> result2 = solution.intersection(nums3, nums4);
    cout << "Test 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}