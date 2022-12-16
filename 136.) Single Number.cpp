class Solution {
public:
    int singleNumber(vector<int>& a) {
        int single = 0;
        for(int i=0;i<a.size();i++)
            single ^= a[i];
        return single;
    }
};