/*
Given a string,
find the length of the longest substring without repeating characters.

Example:
The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstring(string A) {
    
    map<char, int> m;
    int max_len = 0;
    int s = 0;
  
    for(int i=0; i<A.length(); i++)
    {   
        if(m.find(A[i]) != m.end() && m[A[i]]>=s)  // found
            s = m[A[i]]+1;
        m[A[i]] = i;
        max_len = max(max_len, (i-s+1) );
    }
    return max_len;
}
