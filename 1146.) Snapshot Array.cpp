class SnapshotArray {
public:
    vector<unordered_map<int, int>> records;
    int snapId = 0;
    SnapshotArray(int length) {
        records.resize(length);
    }
    
    void set(int index, int val) {
        records[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0 && records[index].find(snap_id) == records[index].end())
            snap_id--;
        
        if(snap_id == -1)
            return 0;
        return records[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */