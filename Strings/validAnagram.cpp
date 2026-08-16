/*242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Test 1: " << boolalpha
         << solution.isAnagram(s1, t1) << endl;

    string s2 = "rat";
    string t2 = "car";
    cout << "Test 2: "
         << solution.isAnagram(s2, t2) << endl;

    string s3 = "listen";
    string t3 = "silent";
    cout << "Test 3: "
         << solution.isAnagram(s3, t3) << endl;

    return 0;
}