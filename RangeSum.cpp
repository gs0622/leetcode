#include <iostream>
#include <vector>
using namespace std;
class NumArray {
private:
 	vector<int> sum; 
public:
    NumArray(vector<int> &nums) {
		if (nums.size()==0) return;
		sum.push_back(nums[0]);
		for (int i=1; i<nums.size(); i++) sum.push_back(nums[i] + sum.back());
	}
    int sumRange(int i, int j) {
		return (i==0)? sum[j]: sum[j]-sum[i-1];
    }
};

int main(void) {
	int arr[] = {-2, 0, 3, -5, 2, -1};
	std::vector<int> v (arr, arr+6);
	NumArray numArray(v);
	cout << numArray.sumRange(0, 2) << endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;
	cout << numArray.sumRange(0, 0) << endl;
	return 0;
}
