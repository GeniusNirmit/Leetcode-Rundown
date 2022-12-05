class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        int n = a[0].length();
        int max = pow(2,n) - 1;
        int temp;
        vector<bool> v(max+1,true);
        for(int i=0;i<a.size();i++)
        {
            temp = 0;
            for(int j=a[i].length()-1;j>=0;j--)
            {
                temp += pow(2,a[i].length()-1-j)*(a[i][j]-'0');
            }
            v[temp] = false;
        }
        string s;
        if(v[0])
        {
            while(n--)
                s += '0';
            return s;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i])
            {
                while(i>0)
                {
                    char bit = i%2 + '0';
                    s = bit + s;
                    i /= 2;
                }
                if(s.length() != n)
                {
                    n -= s.length();
                    while(n--)
                        s = '0' + s;
                }
                return s;
            }
        }
        return s;
    }
};