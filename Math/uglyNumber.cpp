/*263. Ugly Number 

An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
Given an integer n, return true if n is an ugly number.

Example 1:
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: n = 1
Output: true
Explanation: 1 has no prime factors.

Example 3:
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

Constraints:
-231 <= n <= 231 - 1 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 2 == 0) {
            n = n / 2;
        }

        while (n % 3 == 0) {
            n = n / 3;
        }

        while (n % 5 == 0) {
            n = n / 5;
        }

        if (n == 1) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution solution;

    int n1 = 6;
    cout << "Test 1: " << boolalpha << solution.isUgly(n1) << endl;

    int n2 = 1;
    cout << "Test 2: " << solution.isUgly(n2) << endl;

    int n3 = 14;
    cout << "Test 3: " << solution.isUgly(n3) << endl;

    int n4 = 30;
    cout << "Test 4: " << solution.isUgly(n4) << endl;

    return 0;
}