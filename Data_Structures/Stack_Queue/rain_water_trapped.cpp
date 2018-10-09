#include<iostream>
#include<stack>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int l = 0, r = n-1, res = 0, leftMax = 0, rightMax = 0;
  while(l<r) {
    if(a[l]<a[r]) {
      if(leftMax<a[l]) {
        leftMax = a[l];
      } else {
        res += leftMax-a[l];
      }
      l++;
    } else {
      if(rightMax<a[r]) {
        rightMax = a[r];
      } else {
        res += rightMax - a[r];
      }
      r--;
    }
  }
  cout<<res;
  return 0;
}
