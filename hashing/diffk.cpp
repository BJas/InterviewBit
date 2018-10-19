#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main() {
  int n, x, k;
  cin>>n;
  vector<int> v;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x);
  }
  cin>>k;

  map<int, bool> m;
  for(int i=0; i<n; i++) {
    if(m.find(k+v[i]) != m.end() || m.find(v[i]-k) != m.end()) {
      cout<<"Found"<<endl;
    } else {
      m[v[i]] = true;
    }
  }
  cout<<"Not found";
  return 0;
}
