class MinStack {
    stack<long long> st;
    long long min;
public:
    void push(int value) {
        if(st.empty())
        {
            min=value;
            st.push(value);
        }
        else{
            if(value>min)
                st.push(value);
            else{
                st.push(2LL*value-min);
                min=value;
            }
        }
    }
    
    void pop() {
        long long n=st.top();
        st.pop();
        if(n<min){
            min=2*min-n;
        }
    }
    
    int top() {
        long long n=st.top();
        if(min<n)
            return n;
        return min;
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */