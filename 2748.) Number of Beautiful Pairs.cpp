class Solution {
public:
    int countBeautifulPairs(vector<int>& a) {
        int counter = 0;
        for(int i=0; i<a.size(); i++)
        {
            string num1 = to_string(a[i]);
            for(int j=i+1; j<a.size(); j++)
            {
                string num2 = to_string(a[j]);
                if(__gcd(num1[0] - '0', num2[num2.size()-1] - '0') == 1)
                    counter++;
            }
        }
        return counter;
    }
};