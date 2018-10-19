#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main() {
  int n, x;
  cin>>n;
  vector<int> a;
  for(int i=0; i<n; i++) {
    cin>>x;
    a.push_back(x);
  }
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += a[i];
  }
  int l = 0, r = n-1;
  while(l<=r && sum!=0) {
    if((a[l]>a[r] && sum>0) || (a[r]>a[l] && sum<0)) {
      sum -= a[l];
      l++;
    } else {
      sum -= a[r];
      r--;
    }
  }
  for(int i=l; i<=r; i++) {
      cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<l<<" "<<r;
  return 0;
}
