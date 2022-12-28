class Solution {
public:
    bool canJump(vector<int>& a) {
        int jump = 0;
        for(int i=0;i<a.size();i++)
        {
            if(jump<i)
                return false;
            jump = max(jump,i+a[i]);
        }
        return true;
    }
};