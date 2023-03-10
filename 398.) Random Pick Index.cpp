class Solution {
    vector<int> a;
public:
    Solution(vector<int>& nums) {
        a = nums;
    }
    
    int pick(int target) {
        int random = 0, index = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] == target)
            {
                random++;
                if(rand() % random == 0)
                    index = i;
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */