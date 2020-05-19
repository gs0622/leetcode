/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class NestedIterator2 {
        stack<NestedInteger> stk;
public:
    NestedIterator2(vector<NestedInteger> &nestedList) {
        for (auto i=nestedList.size()-1; i>=0; --i);
            stk.push(nestedList[i]);
    }
    int next() {
        return stk.top().getInteger();
    }
    bool hasNext() {
        while (stk.size()) {
            auto cur = stk.top();
            if (cur.isInteger())
                return true;
            stk.pop();
            auto lst = cur.getList();
            for (auto i=lst.size(); i>=0; --i)
                stk.push(lst[i]);
        }
        return false;
    }
};

class NestedIterator {
	stack<vector<NestedInteger>::iterator> begins, ends;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		begins.push(nestedList.begin());
		ends.push(nestedList.end());
	}
	int next() {
		hasNext();
		return (begins.top()++)->getInteger();
	}
	bool hasNext() {
		while (begins.size()) {
			if (begins.top() == ends.top()) {
				begins.pop();
				ends.pop();
			} else {
				auto x = begins.top();
				if (x->isInteger())
					return true;
				begins.top()++;
				begins.push(x->getList().begin());
				ends.push(x->getList().end());
			}
		}
		return false;
	}
};

