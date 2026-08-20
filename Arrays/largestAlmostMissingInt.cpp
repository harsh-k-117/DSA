#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Only one subarray: the whole array
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Count frequency of every number
        int freq[51] = {0};

        for (int num : nums) {
            freq[num]++;
        }

        // If k = 1, find the largest number occurring once
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1) {
                    return i;
                }
            }
        }

        // For 1 < k < n, only first and last can qualify
        int answer = -1;

        if (freq[nums[0]] == 1) {
            answer = max(answer, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            answer = max(answer, nums[n - 1]);
        }

        return answer;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3, 9, 2, 1, 7};
    int k = 3;

    cout << "Largest almost missing integer: "
         << s.largestInteger(nums, k) << endl;

    return 0;
}