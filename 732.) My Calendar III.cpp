class MyCalendarThree
{
    map<int, int> mp;

public:
    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {
        mp[startTime]++;
        mp[endTime]--;

        int maxCounter = 0, counter = 0;

        for (auto i : mp)
        {
            counter += i.second;
            maxCounter = max(maxCounter, counter);
        }

        return maxCounter;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */