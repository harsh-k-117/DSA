/*7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-231 <= x <= 231 - 1 */

class Solution {
public:
    int reverse(int x) {
        int reverse_int = 0;
        int digit = 0;

        while(x!=0){
            if (reverse_int > INT_MAX / 10 ||
                reverse_int < INT_MIN / 10 ||
                (reverse_int == INT_MAX / 10 && digit > 7) ||
                (reverse_int == INT_MIN / 10 && digit < -8)){
                    return 0;
            }
            digit = x%10;
            reverse_int = reverse_int*10+digit;
            x=x/10;
        }
        return reverse_int;
    }
};