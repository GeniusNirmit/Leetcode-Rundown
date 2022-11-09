class MinStack {
public:
    vector<int> v;
    int stack_top=0;
    int stack_size = 0;
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
        stack_top = val;
        stack_size++;
    }
    
    void pop() {
        stack_size--;
        stack_top=v[stack_size-1];
    }
    
    int top() {
        return stack_top;
    }
    
    int getMin() {
        return *min_element(v.begin(),v.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */ 