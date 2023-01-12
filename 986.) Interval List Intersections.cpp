class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int list1 = 0;
        int list2 = 0;
        vector<vector<int>> commonIntervals;
        while(list1<firstList.size() && list2<secondList.size())
        {
            int start = max(firstList[list1][0],secondList[list2][0]);
            int end = min(firstList[list1][1],secondList[list2][1]);
            if(start <= end)
            {
                vector<int> interval(2,0);
                interval[0] = start;
                interval[1] = end;
                commonIntervals.push_back(interval);
            }
            if(firstList[list1][1] >= secondList[list2][1])
                list2++;
            else
                list1++;
        }
        return commonIntervals;
    }
};