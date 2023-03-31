class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& a) {
        vector<string> numberStr;
        string largestNumber;
        for(int i=0;i<a.size();i++)
            numberStr.push_back(to_string(a[i]));

        sort(numberStr.begin(), numberStr.end(), cmp);
        if(numberStr[0] == "0")
            return "0";
        for(int i=0;i<numberStr.size();i++)
            largestNumber += numberStr[i];
        return largestNumber;
    }
};