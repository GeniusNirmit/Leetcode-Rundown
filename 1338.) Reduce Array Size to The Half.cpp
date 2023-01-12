class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    int minSetSize(vector<int>& a) {
        unordered_map<int,int> frequency;
        vector<pair<int,int>> frequencyArr;
        int counter = 0;
        int length = a.size();
        for(int i=0;i<a.size();i++)
            frequency[a[i]]++;
        for(auto i:frequency)
            frequencyArr.push_back(i);
        sort(frequencyArr.begin(),frequencyArr.end(),cmp);
        auto i = frequencyArr.begin();
        while(length > a.size()/2)
        {
            length -= i->second;
            counter++;
            i++;
        }
        return counter;
    }
};