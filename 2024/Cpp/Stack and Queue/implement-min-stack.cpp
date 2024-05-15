// brute force, 
// approach, storing the pairs in a stack, which are (value,min);
// The first element in the pair will store the value and the second element will store the minimum element till now.
// When the first push operation comes in we will push the value and store it as minimum itself in the pair. 
// In the second push operation, we will check if the top element’s minimum is less than the new value. 
// If it is then we will push the value with minimum as the previous top’s minimum. 
// To get the getMin element to take the top’s second element.

// tc: O(1), sc: O(2N)

class MinStack {
        stack<pair<int,int>> st;
public:
    MinStack() {
       
    }
    
    void push(int val) {
         int min;
         if(st.empty()){
            min = val;
         }else {
            min = std::min(st.top().second,val);
         }
         st.push({val,min});
    }
    
    void pop() {
        st.pop();   
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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