// Approach-1

class Solution {
public:
    int findMaxK(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            int l = 0, h = a.size()-1,mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(a[mid]+a[i]==0)
                    return abs(a[i]);
                else if(a[mid]+a[i] > 0)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};

// Approach-2

class Solution {
public:
    int findMaxK(vector<int>& a) {
        unordered_set<int> s(a.begin(),a.end());
        int max = -1;
        for(int i:s)
        {
            if (i>0 && s.find(-i)!=s.end())
            {
                if(i>max)
                    max = i;
            }
        }
        return max;
    }
};