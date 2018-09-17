#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
void maxOnes(int A[], int n, int m) {
  int l = 0, r = 0, zeros = 0, result = 0, left = 0;
  while(r<n) {
    if(zeros<=m) {
      if(A[r]==0)
        zeros++;
      r++;
    }
    if(zeros>m) {
      if(A[l]==0)
        zeros--;
      l--;
    }
    if(r-l>result) {
      result = r-l;
      left = l;
    }
  }
  vector<int> res;
  for(int i=0; i<result; i++)
    res.push_back(i+left);
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int m;
  cin>>m;
  maxOnes(a, n, m);
  return 0;
}
