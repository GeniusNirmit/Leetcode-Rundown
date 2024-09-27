class MyCalendarTwo
{
    map<int, int> mp;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;

        int currentEvents = 0;

        for (auto i : mp)
        {
            currentEvents += i.second;

            if (currentEvents > 2)
            {
                mp[start]--;
                mp[end]++;

                if (mp[start] == 0)
                    mp.erase(start);
                if (mp[end] == 0)
                    mp.erase(end);

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */