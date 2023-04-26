class SmallestInfiniteSet {
public:
    set<int> infiniteSet;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++)
            infiniteSet.insert(i);
    }
    
    int popSmallest() {
        int first = *infiniteSet.begin();
        infiniteSet.erase(infiniteSet.begin());
        return first;
    }
    
    void addBack(int num) {
        infiniteSet.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */