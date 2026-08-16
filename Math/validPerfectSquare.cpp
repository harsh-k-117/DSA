/*367. Valid Perfect Square
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

Constraints:
1 <= num <= 231 - 1 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;

        while (low <= high) {
            int mid = (high + low) / 2;
            long long sq = 1LL * mid * mid;

            if (sq == num) {
                return true;
            }
            else if (sq > num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    int num1 = 16;
    cout << "Test 1: " << boolalpha
         << solution.isPerfectSquare(num1) << endl;

    int num2 = 14;
    cout << "Test 2: "
         << solution.isPerfectSquare(num2) << endl;

    int num3 = 1;
    cout << "Test 3: "
         << solution.isPerfectSquare(num3) << endl;

    int num4 = 2147395600;
    cout << "Test 4: "
         << solution.isPerfectSquare(num4) << endl;

    return 0;
}