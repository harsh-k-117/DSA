/*3345. Smallest Divisible Digit Product I

You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

Constraints:
1 <= n <= 100
1 <= t <= 10 */

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;
            int temp = n;

            while (temp != 0) {
                int digit = temp % 10;
                product *= digit;
                temp /= 10;
            }

            if (product % t == 0) {
                return n;
            }

            n++;
        }

        return 0;
    }
};

int main() {
    Solution solution;

    int n1 = 10;
    int t1 = 2;
    cout << "Test 1: " << solution.smallestNumber(n1, t1) << endl;

    int n2 = 15;
    int t2 = 3;
    cout << "Test 2: " << solution.smallestNumber(n2, t2) << endl;

    int n3 = 11;
    int t3 = 7;
    cout << "Test 3: " << solution.smallestNumber(n3, t3) << endl;

    return 0;
}