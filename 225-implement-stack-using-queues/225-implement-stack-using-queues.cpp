class MyStack {
public:
    
    
    //T.C & S.C -> O(n) & O(n) using two queues;
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1, q2);
    }
    
    int pop() {
        int y = q1.front();
        
        q1.pop();
        
        return y;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        
        return (q1.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */