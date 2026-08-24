/*3622. Check Divisibility by Digit Sum and Product

You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.

Example 1:
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:
Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

Constraints:
1 <= n <= 106 */

#include<iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {

        int original = n;
        int product = 1;
        int sum = 0;

        while(n!=0){
            int digit = n%10;
            product = product * digit;
            sum = sum + digit;
            n = n/10;
        }

        int value = product + sum;

        if(original % value == 0){
            return true;
        }
        return false;

    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << boolalpha << s.checkDivisibility(n) << endl;
    return 0;
}