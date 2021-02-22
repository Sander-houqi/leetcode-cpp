/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include<stack>
using namespace std;

// @lc code=start
class MinStack {
    stack<int> s,min_s;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        // 新插入元素和最小栈比较
        if(min_s.empty() || min_s.top() >= x){
            min_s.push(x);
        }
    }
    
    void pop() {
        //如果相等一起弹出
        if(!min_s.empty() && min_s.top() == s.top()){
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

