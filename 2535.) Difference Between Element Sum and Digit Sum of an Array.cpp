class Solution {
public:
    int differenceOfSum(vector<int>& a) {
        long long digitSum = 0;
        long long elementSum = 0;
        for(int i=0;i<a.size();i++)
            elementSum += a[i];
        for(int i=0;i<a.size();i++)
        {
            int temp = a[i];
            while(temp > 0)
            {
                digitSum += (temp % 10);
                temp /= 10;
            }
        }
        return abs(elementSum - digitSum);
    }
};