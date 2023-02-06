class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> shuffledArray;
        for(int i=0;i<a.size()/2;i++)
        {
            shuffledArray.push_back(a[i]);
            shuffledArray.push_back(a[a.size()/2+i]);
        }
        return shuffledArray;
    }
};