#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n, m;
  cin>>n>>m;
  vector<int> a, b;
  for(int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    a.push_back(temp);
  }
  for(int i=0; i<m; i++) {
    int temp;
    cin>>temp;
    b.push_back(temp);
  }
  int minm = min(a[0], b[0]);
  int maxm = max(a[n-1], b[m-1]);
  int left = minm, right = maxm;
  int req = (minm+maxm+1)/2;
  while(left<right) {
    int mid = left+(right-left)/2;
    int upper1 = upper_bound(a.begin(), a.end(), mid) - a.begin();
    int upper2 = upper_bound(b.begin(), b.end(), mid) - b.begin();
    cout<<upper1<<" "<<upper2<<endl;
    if(upper1+upper2<req)
      left = mid+1;
    else
      right = mid;
  }
  cout<<left<<endl;
  return 0;
}
