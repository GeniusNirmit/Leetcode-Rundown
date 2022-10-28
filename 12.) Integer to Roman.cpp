class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> roman;
        roman.push_back({1000,"M"});
        roman.push_back({900,"CM"});
        roman.push_back({500,"D"});
        roman.push_back({400,"CD"});
        roman.push_back({100,"C"});
        roman.push_back({90,"XC"});
        roman.push_back({50,"L"});
        roman.push_back({40,"XL"});
        roman.push_back({10,"X"});
        roman.push_back({9,"IX"});
        roman.push_back({5,"V"});
        roman.push_back({4,"IV"});
        roman.push_back({1,"I"});
        
        string s;
        int i=0;
        while(i<roman.size() && num>=0)
        {
            if(num>=roman[i].first)
            {
                s += roman[i].second;
                num -= roman[i].first;
            }
            else
                i++;
        }
        return s;
    }
};