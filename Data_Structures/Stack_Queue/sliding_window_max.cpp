#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int k;
  cin>>k;
  deque<int> d;
  vector<int> res;
  for(int i=0; i<k; i++) {
    while(!d.empty() && a[i]>=a[d.back()]) {
      d.pop_back();
    }
    d.push_back(i);
  }
  for(int i=k; i<n; i++) {
    res.push_back(a[d.front()]);
    while(!d.empty() && d.front() <= i-k) {
      d.pop_front();
    }
    while(!d.empty() && a[i]>=a[d.back()]) {
      d.pop_back();
    }
    d.push_back(i);
  }
  res.push_back(a[d.front()]);
  for(int i=0; i<res.size(); i++)
    cout<<res[i]<<" ";
  return 0;
}
