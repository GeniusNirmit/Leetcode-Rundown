class Solution {
public:
    string customSortString(string order, string s) {
        stack<char> orderSt;
        unordered_map<char,int> sMap;
        for(int i=0;i<order.length();i++)
            orderSt.push(order[i]);
        for(int i=0;i<s.length();i++)
            sMap[s[i]]++;
        s = "";
        while(!orderSt.empty())
        {
            if(sMap.find(orderSt.top()) != sMap.end())
            {
                int temp = sMap.find(orderSt.top())->second;
                while(temp--)
                {
                    s += orderSt.top();
                    sMap[orderSt.top()]--;
                }
            }
            orderSt.pop();
        }
        for(auto i:sMap)
        {
            int temp = i.second;
            while(temp--)
            {
                s += i.first;
                sMap[i.first]--;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};