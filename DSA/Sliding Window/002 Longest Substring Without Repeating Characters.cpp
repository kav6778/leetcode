/* https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char, int>mp;

        int ans=0;
        int length =0;
        int tail =0, head =-1;
        // looping through the string 
        // while there is next element to take we will not violate the condition
        while (tail < n){
            while( head +1 <n && (mp[s[head+1]] == 0) ){
                head++;
                mp[s[head]]++;
            }

            // debug
            cout<< tail << " " << head << endl;

            // adjust the answer accordingly
            ans = max(ans, head-tail+1);

            //move tail ahead and remove the last element
            if(head >= tail){
                mp[s[tail]]--;
                tail++;
            }else {
                tail ++;
                head = tail -1;
            }

        }
        return ans;
    }
};
