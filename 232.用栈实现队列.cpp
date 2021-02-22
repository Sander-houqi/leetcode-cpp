/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include<stack>
using namespace std;
// @lc code=start
class MyQueue {
    stack<int> in, out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //out 为空
        in2out();
        //out 不为空
        int x = out.top();
        out.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        in2out();
        //只需要获得，不需要弹出
        return out.top();
    }
    
    // out 栈为空，则in的元素导入out
    void in2out(){
        if(out.empty()){
            while (!in.empty())
            {   
                //只能先取值，然后在pop()
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return  in.empty() && out.empty();
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
// @lc code=end

