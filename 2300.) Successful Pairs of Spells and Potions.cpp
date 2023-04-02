class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> successPairs;

        for(int i=0; i<spells.size(); i++)
        {
            int l = 0, h = potions.size() - 1, mid;
            while(l <= h)
            {
                mid = (l + h)/2;
                if((long long)spells[i] * potions[mid] >= success)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            if(l >= potions.size())
                successPairs.push_back(0);
            else
                successPairs.push_back(potions.size() - l);
        }
        return successPairs;
    }
};