// Approach-1

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
            while(!st.empty() && ((st.top()==(s[i+1]+32)) || (st.top()==(s[i+1]-32))))
            {
                st.pop();
                i++;
            }
        }
        s = "";
        while(!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

// Approach-2

class Solution {
public:
    string makeGood(string s) {
        int h = 0;
        for (int l=0;l<s.size();l++) 
        {
            if (h>0 && ((s[l]==s[h-1]+32) || s[l]==s[h-1]-32))
                h--;
            else
            {
                s[h] = s[l];
                h++;
            }
        }
        return s.substr(0, h);
    }
};