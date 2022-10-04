class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i=a.length()-1,j=b.length()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            if(a[i]=='1' && b[j]=='1')
            {
                if(carry)
                {
                    s += "1";
                    carry=0;
                }
                else
                    s += "0";
                carry=1;   
            }
            else if(a[i]=='1' && b[j]=='0')
            {
                if(carry)
                {
                    s += "0";
                    carry=1;
                }
                else
                    s += "1";
            }
            else if(a[i]=='0' && b[j]=='1')
            {
                if(carry)
                {
                    s += "0";
                    carry=1;
                }
                else
                    s += "1";
            }
            else
            {
                if(carry)
                {
                    s += "1";
                    carry=0;
                }
                else
                    s += "0";
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            if(a[i]=='1')
            {
                if(carry)
                {
                    s += "0";
                    carry=1;
                }
                else
                    s += "1";
            }
            else
            {
                if(carry)
                {
                    s += "1";
                    carry=0;
                }
                else
                    s += "0";
            }
            i--;
        }
        while(j>=0)
        {
            if(b[j]=='1')
            {
                if(carry)
                {
                    s += "0";
                    carry=1;
                }
                else
                    s += "1";
            }
            else
            {
                if(carry)
                {
                    s += "1";
                    carry=0;
                }
                else
                    s += "0";
            }
            j--;
        }
        if(carry)
            s += "1";
        for(int i=0,j=s.length()-1;i<j;i++,j--)
            swap(s[i],s[j]);
        return s;
    }
};