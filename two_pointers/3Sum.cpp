#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
using namespace std;
int threeSum(vector<int> A, int n, int B) {
  sort(A.begin(), A.end());
  int minn = INT_MAX, result=0;
  if(A.size()<3) return result;
  for(int i=0; i<n; i++) {
    int j=i+1, k=n-1, sum = 0;
    while(j<k) {
      sum = A[i]+A[j]+A[k];
      if(abs(sum-B)<minn) {
        minn = abs(sum-B);
        result = sum;
      }
      if(sum<B)
        j++;
      else
        k--;
    }
  }
  return result;
}
int main() {
  int n, target;
  cin>>n;
  vector<int>A(n);
  for(int i=0; i<n; i++)
    cin>>A[i];
  cin>>target;
  int result = threeSum(A, n, target);
  cout<<result;
  return 0;
}
