class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int counter=1;
        int i=0;
        for(int j=1;j<a.size();j++)
        {
            if(a[i] != a[j])
            {
                i++;
                counter++;
                a[i] = a[j];
            }
        }
        return counter;
    }
};