class BrowserHistory {  
    stack<string> backSt, forwardSt;
    string current;
public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        while(!forwardSt.empty())
            forwardSt.pop();
        backSt.push(current);   
        current = url;
    }
    
    string back(int steps) {
        while(!backSt.empty() && steps--)
        {
            forwardSt.push(current);
            current = backSt.top();
            backSt.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while(!forwardSt.empty() && steps--)
        {
            backSt.push(current);
            current = forwardSt.top();
            forwardSt.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */