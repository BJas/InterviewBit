#include<iostream>
#include<map>
#include<vector>
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
  if(k>n)
    cout<<"Empty";
  map<int, int> m;
  vector<int> result;
  int start = 0;
  for(int i=0; i<n; i++) {
    m[v[i]]++;
    if(i>=k-1) {
      result.push_back(m.size());
      m[v[start]]--;
      if(m[v[start]]==0) {
        m.erase(v[start]);
      }
      start++;
    }
  }
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
  return 0;
}
