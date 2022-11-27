class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        vector<double> v;
        multiset<double> s;
        for(int i=0;i<k;i++)
            s.insert(a[i]);
        auto it1 = s.begin();
        auto it2 = s.begin();
        for(int i=0;i<k/2;i++)
            it1++;
        it2 = it1;
        it2--;
        double temp;
        if(k%2==0)
            temp = (*it1+*it2)/2.0;
        else
            temp = *it1;      
        v.push_back(temp);
        for(int i=k;i<a.size();i++)
        {
            s.insert(a[i]);
            if(a[i]<*it1)
                it1--;
            if(a[i-k]<=*it1)
                it1++;
            s.erase(s.lower_bound(a[i-k]));
            it2 = it1;
            it2--;
            if(k%2==0)
                temp = (*it1+*it2)/2.0;
            else
                temp = *it1; 
            v.push_back(temp);
        }
        return v;
    }
};