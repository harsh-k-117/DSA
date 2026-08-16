/*9. Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise. 

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:
-231 <= x <= 231 - 1*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long result = 0;

        while (x > 0) {
            int remainder = x % 10;
            result = (result * 10) + remainder;
            x = x / 10;
        }

        if (original == result) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution solution;

    int x1 = 121;
    cout << "Test 1: " << boolalpha << solution.isPalindrome(x1) << endl;

    int x2 = -121;
    cout << "Test 2: " << solution.isPalindrome(x2) << endl;

    int x3 = 10;
    cout << "Test 3: " << solution.isPalindrome(x3) << endl;

    int x4 = 0;
    cout << "Test 4: " << solution.isPalindrome(x4) << endl;

    return 0;
}