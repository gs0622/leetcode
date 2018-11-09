/*
https://leetcode.com/problems/min-stack/#/description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include <stack>
#include <iostream>
using namespace std;

class MinStack {
private:
	std::stack<int> *pStack;
	std::stack<int> *pMin;
public:
    /** initialize your data structure here. */
    MinStack() {
        pStack = new std::stack<int>();
        pMin = new std::stack<int>();
    }
    void push(int x) {
		pStack->push(x);
		if (pMin->empty() || x <= pMin->top()) // '<=' is important 
			pMin->push(x);
    }
    void pop() {
		int top = pStack->top();
		pStack->pop();
		if (top == pMin->top())
			pMin->pop();
    }
    int top() {
        return pStack->top();
    }
    int getMin() {
        return pMin->top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main() {
	MinStack *obj = new MinStack();
	obj->push(1);
	obj->push(4);
	obj->push(3);
	obj->push(0);
	obj->push(3);
	//obj->pop();
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	cout << param_3 << " " << param_4 << endl;
	return 0;
}
