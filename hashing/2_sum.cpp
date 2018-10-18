#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void getSum(vector<int> &v, int k) {
  unordered_map<int, int> m;
  for(int i=0; i<v.size(); i++) {
    if(m.find(k-v[i])!=m.end()) {
      cout<<"index:"<<m[k-v[i]]<<" "<<i;
    }
    if(m.find(v[i])==m.end())
      m[v[i]] = i;
  }
}
int main() {
  int n, x, k;
  cin>>n;
  vector<int> arr;
  for(int i=0; i<n; i++) {
    cin>>x;
    arr.push_back(x);
  }
  cin>>k;
  getSum(arr, k);
  return 0;
}
