class MinStack {
public:
    int minElement = INT_MAX;
    stack<int>st;
    void findMin(stack<int>&st){
        if(st.empty()){
            return;
        }

        int val = st.top();
        st.pop();

        findMin(st);

        minElement = min(minElement,val);
        st.push(val);
    }
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        minElement = min(minElement,val);
    }
    
    void pop() {
        st.pop();
        minElement = INT_MAX;
        findMin(st);
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
    
    int getMin() {
        return minElement;
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