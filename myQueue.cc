/* https://leetcode.com/problems/implement-queue-using-stacks/description/
*/
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
	stack<int> in, out;
public:
	MyQueue() {}
	void push(int x) {
		in.push(x);
	}
	int pop() {
		peek();
		int v = out.top();
		out.pop();
		return v;
	}
	int peek() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top()); in.pop();
			}
		}
		return out.top();
	}
	bool empty() { return in.empty() && out.empty(); }
};
int main(){
	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
}
