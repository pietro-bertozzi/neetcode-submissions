class MinStack {
public:
    stack<int> normalStack;
    stack<int> minStack;

    MinStack() {

    }
    
    void push(int val) {
        if (minStack.empty() || val <= minStack.top()) minStack.push(val);
        normalStack.push(val);
    }
    
    void pop() {
        if (normalStack.empty()) return;
        if (minStack.empty() || normalStack.top() == minStack.top()) minStack.pop();
        normalStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
