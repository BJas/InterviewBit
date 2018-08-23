#include <iostream>
#include <cmath>
using namespace std;
void maxSubArray(int a[], int n) {
  int right = 0, max_sum = 0, l=0, r=0, max_len = 0;
  for(int i=0; i<n; i++) {
    int sum = 0;
    int left = i;
    while(a[i]>=0 && i<n) {
      sum += a[i];
      i++;
    }
    right = i-1;
    if(sum>max_sum || (max_sum == sum && right-left+1>max_len)) {
      l = left;
      r = right;
      max_sum = sum;
      max_len = r-l+1;
    }
  }
  for(int i=l; i<=r; i++) {
    cout<<a[i]<<" ";
  }
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  maxSubArray(a, n);
  return 0;
}
