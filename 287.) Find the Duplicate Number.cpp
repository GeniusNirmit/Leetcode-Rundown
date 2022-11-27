// Approach-1

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            int l = 0,h = a.size()-1,mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(mid != i && a[mid] == a[i])
                    return a[mid];
                else if(a[mid] > a[i])
                    h = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return 0;
    }
};

// Approach-2

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        for(int i=0;i<a.size();i++)
        {
            int index = abs(a[i]);
            if (a[index] < 0) 
                return index;
            a[index] = -a[index];
        }
        return 0;
    }
};