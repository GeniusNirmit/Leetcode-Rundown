// Approach-1

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        k %= a.size();
        reverse(a.begin(),a.begin()+a.size()-k);
        reverse(a.begin()+a.size()-k,a.end());
        reverse(a.begin(),a.end());
    }
};
