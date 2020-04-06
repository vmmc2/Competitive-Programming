class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> enqst;
    stack<int> deqst;
    MyQueue() {
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        enqst.push(x);
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret;
        if(!deqst.empty()){
            ret = deqst.top();
            deqst.pop();
        }else{
            while(!enqst.empty()){
                deqst.push(enqst.top());
                enqst.pop();
            }
            ret = deqst.top();
            deqst.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int ret;
        if(!deqst.empty()){
            ret = deqst.top();
        }else{
            while(!enqst.empty()){
                deqst.push(enqst.top());
                enqst.pop();
            }
            ret = deqst.top();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(deqst.size() == 0 && enqst.size() == 0) return true;
        return false;
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
