class Solution {
public:
    int averageValue(vector<int>& a) {
        long long sum = 0;
        int counter = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]%6==0)
            {
                sum += a[i];
                counter++;
            }
        }
        if(!counter)
            return 0;
        return sum/counter;
    }
};