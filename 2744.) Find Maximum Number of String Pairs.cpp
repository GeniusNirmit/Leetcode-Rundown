class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int counter = 0;
        
        for(int i=0; i<words.size(); i++)
        {
            string temp = words[i];
            sort(temp.begin(), temp.end());
            mp[temp]++;
        }
        
        for(auto i: mp)
            counter += (i.second / 2);
        
        return counter;
    }
};