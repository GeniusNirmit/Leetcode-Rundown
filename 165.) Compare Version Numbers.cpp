// Approach-1

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1=version1.length();
        int l2=version2.length();
        int i=0,j=0;
        int num1,num2;
        while(i<l1 || j<l2)
        {
            num1=0;
            num2=0;
            while(i<l1 && version1[i]!='.')
            {
                num1 = num1*10+(version1[i]-'0');
                i++;
            }
            
            while(j<l2 && version2[j]!='.')
            {
                num2 = num2*10+(version2[j]-'0');
                j++;
            }
            if(num1>num2)
                return 1;
            else if(num1<num2)
                return -1;
            i++;
            j++;
        }
        return 0;
    }
};

// Approach-2

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string s1="",s2="";
        int i=0,j=0;
        while(i<version1.size() || j<version2.size()) 
        { 
            while (i<version1.size() && version1[i]=='0') 
                i++;
            while (i<version1.size() && version1[i]!='.') 
            {
                s1+=version1[i];
                i++;
            }
            while(j<version2.size() && version2[j]=='0')
                j++;
            while(j<version2.size() && version2[j]!='.') 
            {
                s2+=version2[j];
                j++;
            }
            if(s1.size()>s2.size())
                return 1;
            else if(s1.size()<s2.size())
                return -1;
            for(int k=0;k<s1.size();k++) 
            {
                if(s1[k]>s2[k]) 
                   return 1;
                else if(s1[k]<s2[k])
                   return -1;
            }
            s1="";
                s2="";
            i++;
            j++;
        }
        return 0;
    }
};