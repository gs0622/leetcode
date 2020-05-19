/* https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.

hint: reservoir sampling
*/
#include <bits/stdc++.h>
using namespace std;
class Solution2 {
  vector<vector<int>> rt;
  map<int,int> mp;
  int sum=0;
public:
  Solution2(vector<vector<int>> rects): rt(rects) {
    for (auto i=0; i<rt.size(); ++i) {
      sum+=(rt[i][2]-rt[i][0]+1)*(rt[i][3]-rt[i][1]+1);
      mp[sum]=i;
    }
    srand(0);
  }
  vector<int> pick() {
    int rnd=rand()%sum;
    auto upper=mp.upper_bound(rnd);
    vector<int> r=rt[upper->second];
    int x=r[0]+rand()%(r[2]-r[0]+1);
    int y=r[1]+rand()%(r[3]-r[1]+1);
    return {x,y};
  }
};
class Solution {
  vector<vector<int>> rt;
  map<int,int> mp;
  int sum=0;
public:
  Solution(vector<vector<int>> rects): rt(rects) {
    int n=rt.size();  // x1,y1,x2,y2
    for (int i=0; i<n; ++i) {
      sum+=(rt[i][2]-rt[i][0]+1)*(rt[i][3]-rt[i][1]+1); // woraround input as line 
      mp[sum]=i;
    }
    srand(time(0));
  }
  vector<int> pick() {
    // randomly pick rect
    int rnd=rand()%sum;
    auto up=mp.upper_bound(rnd);  // randomly pick rect, apply O(log(n)) to get upper bound area, index
    vector<int> r=rt[up->second]; // select rectangle (or line)

    // pick point by the random within the rect
    int x=r[0]+(up->first-rnd-1)%(r[2]-r[0]+1); // Serialize a point (x,y) in the rectangle to an integer:
    int y=r[1]+(up->first-rnd-1)/(r[2]-r[0]+1); // id = (y-y0) * width + (x - x0), so (y-y0) = id / width, (x-x0) = id % width
    return {x,y};
  }
};

int main(){
  vector<vector<int>> A1{{1,1,5,5}};
  Solution s(A1);
  auto p = s.pick();
  cout << p[1] << "," << p[1] << endl;
  vector<vector<int>> A2{{-2,-2,-1,-1},{1,0,3,0}};
  Solution s2(A2);
  auto p2 = s2.pick();
  cout << p2[1] << "," << p2[1] << endl;
}
