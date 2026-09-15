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
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            freq[t[i]]--;
        }

        for(auto pair : freq){
            if (pair.second != 0){
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