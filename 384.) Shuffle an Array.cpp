class Solution {
public:
    vector<int> duplicate;
    vector<int> original;
    Solution(vector<int>& a) {
        for(int i=0;i<a.size();i++)
        {
            duplicate.push_back(a[i]);
            original.push_back(a[i]);
        }
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int random = rand() % duplicate.size();
        swap(duplicate[0],duplicate[random]);
        return duplicate;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */