#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> v;
	v[0]=1;
	for (auto x: v) cout << x << " ";
	cout << endl;
}
