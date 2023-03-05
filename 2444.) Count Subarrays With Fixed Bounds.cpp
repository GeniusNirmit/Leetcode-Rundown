class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        long long counter = 0;
        int minPosition = -1, maxPosition = -1, left = -1;

        for(int i=0;i<a.size();i++)
        {
            if(a[i] < minK || a[i] > maxK)
                left = i; 
            if(a[i] == minK)
                minPosition = i;
            if(a[i] == maxK)
                maxPosition = i;
            
            counter += max(0, min(maxPosition, minPosition) - left);
        }
        return counter;
    }
};