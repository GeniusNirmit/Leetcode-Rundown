class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        if(a.size()<=2)
            return a.size();
        int counter = 2;
        for(int i=2;i<a.size();i++)
        {
            if(a[counter-2] != a[i])
            {
                a[counter] = a[i];
                counter++;
            }
        }
        return counter;
    }
};