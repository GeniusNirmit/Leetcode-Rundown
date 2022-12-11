class StockSpanner {
public:
    unordered_map<int,int> mp;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int counter = 1;
        while(!st.empty() && price>=st.top())
        {
            counter += mp[st.top()];
            st.pop();
        }
        st.push(price);
        mp[price] = counter;
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */