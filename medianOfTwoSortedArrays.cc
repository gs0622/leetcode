#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	O((m+n)/2) time and space
	double median1(vector<int> nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		vector<int> dummy;
		auto i=begin(nums1), j=begin(nums2);
		for (int k=0; k<=(m+n)/2; ++k) {	// ((m+n)/2)+1, e.g. 5/2=2(0,1,2), 4/2=2(0,1,2,3)
			if (i==nums1.end()) dummy.push_back(*j++);
			else if (j==nums2.end()) dummy.push_back(*i++);
			else if (*i < *j) dummy.push_back(*i++);
			else dummy.push_back(*j++);
		}
		return (m+n)%2? dummy.end()[-1]: (dummy.end()[-1]+dummy.end()[-2])/2.0;
	}
	// O((m+n)log(m+n))
	double median(vector<int> nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		vector<int> nums;
		nums.reserve(m+n);
		nums.insert(begin(nums), begin(nums1), end(nums1));
		nums.insert(begin(nums), begin(nums2), end(nums2));
		sort(begin(nums), end(nums));
		//for_each(begin(nums), end(nums), [](int n){cout << n << ' ';}); cout << endl;
		auto med= (m+n)/2 -1;
		return ((m+n)%2) ? nums[med+1]: (nums[med]+nums[med+1])/2.0; 
	}
};
using namespace std;
int main(){
	vector<int> nums1(4), nums2(7);
	srand(time(0));
	generate_n(begin(nums1), 4, [](){ return rand()%10; });
	generate_n(begin(nums2), 7, [](){ return rand()%10; });
	sort(begin(nums1), end(nums1));
	sort(begin(nums2), end(nums2));
	Solution s;
	cout << s.median(nums1, nums2) << ' ';
	cout << s.median1(nums1, nums2) << endl;

	vector<int> nums3{1,2}, nums4{3,4};
	cout << s.median(nums3, nums4) << ' ';
	cout << s.median1(nums3, nums4) << endl;

}
