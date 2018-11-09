#include <bits/stdc++.h>
using namespace std;
class StockSpanner2 {
	vector<pair<int,int>> stk;
public:
	StockSpanner2() { stk.clear(); }
	// O(1)?
	int next(int price) {
		int span = 1;
		while (!stk.empty() && stk.back().first <= price)	// 2n operations, out then in, when n calls
			span += stk.back().second, stk.pop_back();
		stk.push_back({price, span});
		return span;
	}
};
class StockSpanner {
	vector<int> stk;
public:
	StockSpanner() { stk.clear(); }
	// O(n)?
	int next(int price) {
		stk.push_back(price);
		int span = 0;
		for (auto it=stk.rbegin(); it!=stk.rend(); ++it, ++span)
			if (price < *it) break;
		return span;
	}
};
int main(){
	StockSpanner s1;
	StockSpanner2 s2;
	vector<int> A{100, 80, 60, 70, 60, 75, 85};
	for (auto price: A) {
		cout << s1.next(price) << ": ";
		cout << s2.next(price) << endl;
	}
}
