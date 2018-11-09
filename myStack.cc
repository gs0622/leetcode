/* https://leetcode.com/problems/implement-stack-using-queues/description/ */
#include <iostream>
#include <queue>
using namespace std;
class MyStack {
	queue<int> q;
public:
	/** Initialize your data structure here. */
	MyStack() {}

	/** Push element x onto stack. */
	void push(int x) { /* O(n) */
		q.push(x);
		for (int i=0; i<q.size()-1; ++i) { // key: rolling all the rest before q.back()
			q.push(q.front());
			q.pop();	
		}
	}
    
	/** Removes the element on top of the stack and returns that element. */
	int pop() { int v=q.front(); q.pop(); return v; }

	/** Get the top element. */
	int top() { return q.front(); }

	/** Returns whether the stack is empty. */
	bool empty() { return q.empty(); }
};
int main(){
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << endl;
}
