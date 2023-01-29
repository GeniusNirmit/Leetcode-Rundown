class SummaryRanges {
    vector<vector<int>> intervals;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vector<vector<int>> updatedIntervals;
        vector<int> newInterval;
        newInterval.push_back(value);
        newInterval.push_back(value+1);
        vector<int> tempInterval = newInterval;
        for(int i=0;i<this->intervals.size();i++)
        {
            if(this->intervals[i][0] > newInterval[1])
            {
                updatedIntervals.push_back(tempInterval);
                tempInterval = this->intervals[i];
            }
            else if(this->intervals[i][1] < newInterval[0])
                updatedIntervals.push_back(this->intervals[i]);
            else
            {
                tempInterval[0] = min(tempInterval[0],this->intervals[i][0]);
                tempInterval[1] = max(tempInterval[1],this->intervals[i][1]);
            }
        }
        updatedIntervals.push_back(tempInterval);
        this->intervals = updatedIntervals;
    }
    
    vector<vector<int>> getIntervals() {
        auto currentIntervals = this->intervals;
        for(int i=0;i<currentIntervals.size();i++)
            currentIntervals[i][1]--;
        return currentIntervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */