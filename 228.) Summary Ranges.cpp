class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> summary;
        if(a.size() == 0)
            return summary;
        long long index = a[0];
        string start = to_string(a[0]);
        string end;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != index)
            {
                end = to_string(a[i-1]);
                if(start == end)
                    summary.push_back(start);    
                else
                    summary.push_back(start + "->" + end);
                index = (long long)a[i] + 1;
                start = to_string(a[i]);
            }
            else
                index++;
        }
        end = to_string(a[a.size()-1]);
        if(start == end)
            summary.push_back(start);    
        else
            summary.push_back(start + "->" + end);
        return summary;
    }
};