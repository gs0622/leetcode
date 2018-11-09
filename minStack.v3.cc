#include <iostream>
#include <stack>
using namespace std;
class MinStack {
	stack<int> stk;
	stack<int> min;
public:
    /** initialize your data structure here. */
	MinStack() {}
	void push(int x) {
		stk.push(x);
		if (min.empty() || x <= min.top())
			min.push(x);
	}
	void pop() {
		if (stk.top() == min.top())
			min.pop();
		stk.pop();
	}
	int top() {
		return stk.top();
	}
	int getMin() {
		return min.top();
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
int main(){
	MinStack obj;
	obj.push(-1);
	obj.push(4);
	obj.push(3);
	obj.push(0);
	obj.push(3);
	obj.pop();
	cout << obj.top() << " " << obj.getMin() << endl;
}
