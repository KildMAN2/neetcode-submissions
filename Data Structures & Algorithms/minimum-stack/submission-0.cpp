class MinStack {
private:
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {    
    }
    
    void push(int val) {
        st.push(val);
        int m = min((minStack.empty() ? val : minStack.top() ), val);
        minStack.push(m);

        
    }
    
    void pop() {
        st.pop();
        minStack.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
       return minStack.top();
        
    }
};
