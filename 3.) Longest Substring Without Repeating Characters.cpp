class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char,int> mp;
        int l = 0,h = 0;
        while(h<s.length())
        {
            mp[s[h]]++;
            while(mp[s[h]]==2)
            {
                mp[s[l]]--;
                l++;
            }
            if(max < (h-l)+1)
                max = (h-l)+1;
            h++;
        }
        return max;
    }
};