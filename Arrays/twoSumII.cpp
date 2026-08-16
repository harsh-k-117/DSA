/*167. Two Sum II - Input array is sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

Constraints:
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000

The tests are generated such that there is exactly one solution.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans = {};

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            else if (numbers[left] + numbers[right] < target) {
                left++;
            }
            else if (numbers[left] + numbers[right] > target) {
                right--;
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

    vector<int> numbers1 = {2, 7, 11, 15};
    vector<int> result1 = solution.twoSum(numbers1, 9);
    cout << "Test 1: ";
    printVector(result1);

    vector<int> numbers2 = {2, 3, 4};
    vector<int> result2 = solution.twoSum(numbers2, 6);
    cout << "Test 2: ";
    printVector(result2);

    vector<int> numbers3 = {-1, 0};
    vector<int> result3 = solution.twoSum(numbers3, -1);
    cout << "Test 3: ";
    printVector(result3);

    return 0;
}