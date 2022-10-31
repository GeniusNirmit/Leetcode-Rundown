// Approach-1

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        unordered_map<int , int> mp;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        for(auto i:mp)
        {
            if(i.second==1)
                return i.first;
        }
        return -1;
    }
};

// Approach-2

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)
            return a[0];
        if(a[0]!=a[1])
            return a[0];
        if(a[a.size()-1]!=a[a.size()-2])
            return a[a.size()-1];
        int l=0,h=a.size()-1,mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(a[mid] != a[mid+1] && a[mid] != a[mid-1])
                return a[mid];
            else if((a[mid] == a[mid+1] && mid%2==0) || (a[mid] == a[mid-1] && mid%2!=0))
                l = mid + 1;
            else 
                h = mid - 1;
        }
        return -1;
    }
};