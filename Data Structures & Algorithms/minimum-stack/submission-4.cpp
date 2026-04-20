class MinStack {
    stack<int> minSt ,st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int toAdd = min(val , minSt.empty() ? val : minSt.top());
        minSt.push(toAdd);
        
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        minSt.pop();
        
    }
    
    int top() {
       return  st.top();
        
    }
    
    int getMin() {
       return minSt.top();
        
    }
};
