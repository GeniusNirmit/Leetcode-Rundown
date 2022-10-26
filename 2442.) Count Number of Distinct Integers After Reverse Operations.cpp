class Solution {
public:
    int countDistinctIntegers(vector<int>& a) {
        unordered_set<int> s(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            int temp=a[i];
            string number;
            while(temp>0)
            {
                char x = '0'+(temp%10);
                number += x;
                temp/=10;
            }
            int num = stoi(number);
            s.insert(num);
        }
        return s.size();
    }
};