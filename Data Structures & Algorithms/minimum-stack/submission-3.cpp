class MinStack {
    private:
        std::stack<int>minStack; 
        std::stack<int>stack;
public:
    MinStack() {   
    }
    
    void push(int val) {
        stack.push(val);
        minStack.empty() ? minStack.push(val) : minStack.push(min(val,minStack.top()));
    }
    
    void pop() {
        if(stack.empty())
        {
            return;
        }
        int pop = stack.top();
        stack.pop();
        minStack.pop();
    
        
    }
    
    int top() {
        return stack.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
};
