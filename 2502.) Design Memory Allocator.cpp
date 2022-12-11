class Allocator {
    vector<int> v;
public:
    Allocator(int n) {
       vector<int> temp(n,0); 
        v = temp;
    }
    
    int allocate(int sizeNew, int mID) {
        int first = 0;
        int Size = sizeNew;
        bool flag = false;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
            {
                Size--;
                if(!Size)
                {
                    first = i - sizeNew + 1;
                    flag = true;
                    break;
                }
            }
            else
                Size = sizeNew;
        }
        if(flag)
        {
            int i = first;
            Size = sizeNew;
            while(Size--)
            {
                v[i] = mID;
                i++;
            }
            return first;   
        }
        return -1;
    }
    
    int free(int mID) {
        int counter = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == mID)
            {
                counter++;
                v[i] = 0;
            }
        }
        return counter;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */