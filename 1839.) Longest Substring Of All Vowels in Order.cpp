class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxLength = 0;
        set<char> st;
        int i=0, j=1;
        st.insert(word[0]);

        for( ; j<word.size(); j++)
        {    
            if(word[j-1] > word[j])
            {
                i = j;
                st.clear();
            }

            st.insert(word[j]);

            if(st.size()>=5)
                maxLength = max(maxLength, j-i+1);
        }
        return maxLength;
    }
};