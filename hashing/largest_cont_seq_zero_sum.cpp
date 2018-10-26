#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main() {
  int n, x;
  cin>>n;
  vector<int> v;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x);
  }
  unordered_map<int, int> m;
  m[0] = -1;
  int sum = 0, l = 0, r = n-1, len = 0;
  for(int i=0; i<n; i++) {
    sum += v[i];
    if(m.find(sum)!=m.end() && i-m[sum]>len) {
      l = m[sum]+1;
      r = i;
      len = i-m[sum];
    }  else {
      m[sum] = i;
    }
  }
  for(int i=l; i<=r; i++) {
    cout<<v[i]<<" ";
  }
  return 0;
}
