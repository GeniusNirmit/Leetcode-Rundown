// Approach-1

class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        int temp = a.size()/3;
        for(auto i:mp)
        {
            if(i.second>temp)
                v.push_back(i.first);
        }
        return v;
    }
};

// Approach-2

class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int> v;
        int n1,n2,counter1=0,counter2=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==n1)
                counter1++;
            else if(a[i]==n2)
                counter2++;
            else if(counter1==0)
            {
                n1=a[i];
                counter1++;
            }
            else if(counter2==0)
            {
                n2=a[i];
                counter2++;
            }
            else
            {
                counter1--;
                counter2--;
            }
        }
        counter1=0,counter2=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==n1)
                counter1++;
            if(a[i]==n2)
                counter2++;
        }
        if(counter1>a.size()/3)
            v.push_back(n1);
        if(counter2>a.size()/3)
            v.push_back(n2);
        return v;
    }
};