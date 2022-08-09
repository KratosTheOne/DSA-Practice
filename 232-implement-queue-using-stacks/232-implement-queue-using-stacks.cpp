class MyQueue {
public:
    // T.C & S.C -> O(1)Amortized O(2*n) 
    
    stack<int> in, out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        in.push(x);
    }
    
    int pop() {
        
        if(out.empty())
            while(in.size())
                out.push(in.top()), in.pop();
        
        int popped = out.top();
        out.pop();
        return popped;
    }
    
    int peek() {
        
        if(out.empty())
            while(in.size())
                out.push(in.top()), in.pop();
        
        return out.top();
    }
    
    bool empty() {
        
        return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */