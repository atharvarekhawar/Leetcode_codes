class MyQueue {
public:
   stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
      stackPush(x);
    }

    void stackPush(int x){
        if(s.empty()){
            s.push(x);
            return;
        }

        int num=s.top();
        s.pop();

        stackPush(x);
        s.push(num);
    }
    
    int pop() {
        if(!s.empty()){
            int val=s.top();
            s.pop();
            return val;
        }
        else{
            return -1;
        }
    }
    
    int peek() {
        if(!s.empty()){
            return s.top();
        }
        else{
            return -1;
        }
    }
    
    bool empty() {
        return s.empty();
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