class Solution {
public:
    long long findTheArrayConcVal(vector<int>& a) {
        int i = 0,j = a.size()-1;
        long long concatValue = 0;
        while(i<j)
        {
            concatValue += stoll(to_string(a[i]) + to_string(a[j]));
            i++;
            j--;
        }
        if(i==j)
            concatValue += a[i];
        return concatValue;
    }
};