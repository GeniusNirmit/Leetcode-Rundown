class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int minDeviation = INT_MAX;
        multiset<int> elements;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]%2 == 1)
                a[i] *= 2;
            elements.insert(a[i]);
        }
        while(true)
        {
            int max = *elements.rbegin();
            minDeviation = min(minDeviation, *elements.rbegin() - *elements.begin());
            auto last = elements.end();
            last--;
            elements.erase(last);
            if(max % 2 == 1)
                break;
            elements.insert(max/2);
        }
        return minDeviation;
    }
};