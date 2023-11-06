class SeatManager
{
    multiset<int> pq;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            pq.insert(i);
    }

    int reserve()
    {
        int seat = *pq.begin();
        pq.erase(seat);
        return seat;
    }

    void unreserve(int seatNumber)
    {
        pq.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */