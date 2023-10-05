class MyHashMap
{
public:
    vector<int> mp;
    MyHashMap()
    {
        mp.resize(10, -1);
    }

    void put(int key, int value)
    {
        int n = mp.size();
        if (key >= n)
            mp.resize(n + key + 1, -1);
        mp[key] = value;
    }

    int get(int key)
    {
        int n = mp.size();
        if (key < n)
            return mp[key];
        return -1;
    }

    void remove(int key)
    {
        int n = mp.size();
        if (key < n)
            mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */