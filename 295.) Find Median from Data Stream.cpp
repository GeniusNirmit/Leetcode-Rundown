class MedianFinder {
    multiset<int> s;
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        s.insert(num);
    }
    double findMedian() {    
        auto i= s.begin();
        int k=s.size()/2;
        for(int j=0;j<k;j++)
        i++;
        if(s.size()%2==0)
        {
            int x=*i;
            i--;
            int y=*i;        
            return (x+y)/(double)2.0;
        }
        return (double)*i;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */