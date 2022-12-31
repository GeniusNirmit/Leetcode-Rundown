// Approach-1

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};

// Approach-2

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int p = 0;
        int q = 0;
        for(int i=0;i<pushed.size();i++)
        {
            pushed[p] = pushed[i];
            p++;
            while(p>0 && pushed[p-1]==popped[q])
            {
                p--;
                q++;
            }
        }
        if(p==0)
            return true;
        return false;
    }
};