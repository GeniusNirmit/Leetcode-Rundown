class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hashMap;
        string minimumStringWindow;
        int windowCounter = s.length();
        for(int i=0;i<t.length();i++)
            hashMap[t[i]]++;
        int hashMapSize = hashMap.size();
        int j = 0;
        for(int i=0;i<s.length();i++)
        {
            if(hashMap.find(s[i])!=hashMap.end())
            {
                hashMap[s[i]]--;
                if(hashMap[s[i]]==0)
                    hashMapSize--;
            }
            if(hashMapSize==0)
            {
                while(j<i)
                {
                    if(hashMap.find(s[j])==hashMap.end())
                        j++;
                    else if(hashMap.find(s[j])!=hashMap.end() && hashMap[s[j]]<0)
                    {
                        hashMap[s[j]]++;
                        if(hashMap[s[j]]==1)
                            hashMapSize++;
                        j++;
                    }
                    else if(hashMap.find(s[j])!=hashMap.end() && hashMap[s[j]]==0)
                        break;
                }
                if(i-j+1<=windowCounter)
                {
                    minimumStringWindow = s.substr(j,i-j+1);
                    windowCounter = i-j+1;
                }
            }
        }
        return minimumStringWindow;
    }
};