/* https://leetcode.com/problems/median-of-two-sorted-arrays/description/
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/
#include <bits/stdc++.h>
using namespace std;
/* 
  0....i-1 | i .... m
  0....j-1 | j .... n
*/
class Solution {
public:
	double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		function<int(int [],int,int [],int,int)> kth=[&](int a[], int mm, int b[], int nn, int k){
			if (mm<nn) return kth(b,nn,a,mm,k);
			if (nn==0) return a[k-1];
			if (k==1) return min(a[0],b[0]); 
			int j=min(nn,k/2), i=k-j;
			if (a[i-1]>b[j-1]) return kth(a,i,b+j,nn-j,k-j);
			else return kth(a+i,mm-i,b,j,k-i);
		};
		int k=(m+n)/2;
		int m1=kth(nums1.data(),m,nums2.data(),n,k+1);
		if ((m+n)%2==0) return (kth(nums1.data(),m,nums2.data(),n,k)+m1)/2.0;
		return m1;
	}
	int kth(int a[], int m, int b[], int n, int k) {
		if (m < n) return kth(b,n,a,m,k);
		if (n==0) return a[k-1];
		if (k==1) return min(a[0],b[0]);
		int j = min(n,k/2);
		int i = k-j;
                if (a[i-1] > b[j-1]) return kth(a,i,b+j,n-j,k-j);
                return kth(a+i,m-i,b,j,k-i);
	}

	double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		int k = (m+n)/2;
		int m1 = kth(nums1.data(),m,nums2.data(),n,k+1);
		if ((m+n)%2==0) {
			//int m2 = kth(nums1.data(),m,nums2.data(),n,k);
			//return ((double)m1+m2)/2.0;
			return (kth(nums1.data(),m,nums2.data(),n,k)+m1)/2.0;
		}
		return m1;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		if (m<n) return findMedianSortedArrays(nums2, nums1);	// expect nums2 is shorter
	
		int lo=0, hi=n*2;
		while (lo<=hi) {
			int mi2= lo+(hi-lo)/2, mi1=m+n-mi2;
			double L1=(mi1==0)? INT_MIN: nums1[(mi1-1)/2];
			double L2=(mi2==0)? INT_MIN: nums2[(mi2-1)/2];
			double R1=(mi1==m*2)? INT_MAX: nums1[mi1/2];
			double R2=(mi2==n*2)? INT_MAX: nums2[mi2/2];
			if (L1>R2) lo=mi2+1;
			else if (L2>R1) hi=mi2-1;
			else return (max(L1,L2)+min(R1,R2))/2;
		}
		return -1;

	}
/* 
 nums1: 0....i-1 | i .... m	shorter
 nums2: 0....j-1 | j .... n
*/
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size(), n=nums2.size();
		if (m>n) return findMedianSortedArrays(nums2, nums1);	// expect nums1 is shorter
		int lo=0, hi=m, half_len=(m+n+1)/2;
		while (lo<=hi) {
			int i=lo+(hi-lo)/2;
			int j=half_len-i;
			if (i<m && nums2[j-1] > nums1[i]) // i is too small
				lo=i+1;
			else if (i>0 && nums1[i-1] > nums2[j]) // i is too large
				hi=i-1;
			else {
				int max_left, min_right;
				if (i==0) max_left = nums2[j-1];
				else if (j==0) max_left = nums1[i-1];
				else max_left = std::max(nums1[i-1], nums2[j-1]);

				if ((m+n)%2) return max_left; // see (m+n+1)/2 

				if (i==m) min_right = nums2[j];
				else if (j==n) min_right = nums1[i];
				else min_right = std::min(nums1[i], nums2[j]);

				return (max_left+min_right)/2.0;
			}
		}
		
	}
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums(nums1); // copy nums1
		nums.insert(nums.end(), nums2.begin(), nums2.end()); // merge nums2
		std::sort(nums.begin(), nums.end());
		int sz = nums.size();
		if (sz % 2) return nums[sz/2]; // index from 0
		else return ((double)nums[sz/2-1] + (double)nums[sz/2])/2;
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
int main(){
	vector<int> nums1{1,2};
	vector<int> nums2{3,4};
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	cout << s.findMedianSortedArrays3(nums1, nums2) << endl;
	cout << s.findMedianSortedArrays4(nums1, nums2) << endl;
}
