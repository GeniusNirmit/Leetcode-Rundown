class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int l=0,h=a.size()-1;
        while(l<=h)
        {
            if(a[h]==val)
                h--; 
            else if(a[l]==val)
            {
                swap(a[l],a[h]);
                l++;
                h--;
            }
            else
                l++;
        }
        int counter=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=val)
                counter++;
        }
        return counter;
    }
};
