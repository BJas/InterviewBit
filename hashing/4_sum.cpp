#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void getSum(vector<int> &a, vector<vector<int> > &result, int k) {
  unordered_map<int, pair<int, int> > m;
  for(int i=0; i<a.size()-1; i++)
    for(int j=i+1; j<a.size(); j++)
      m[a[i]+a[j]] = make_pair(i, j);
  int rem;
  for(int i=0; i<a.size()-1; i++) {
    for(int j=i+1; j<a.size(); j++) {
      rem = k-(a[i]+a[j]);
      if(m.find(rem) != m.end()) {
        if(i != m[rem].first && i != m[rem].second
           && j != m[rem].first && j != m[rem].second) {
          vector<int> temp;
          temp.push_back(a[i]);
          temp.push_back(a[j]);
          temp.push_back(a[m[rem].first]);
          temp.push_back(a[m[rem].second]);
          sort(temp.begin(), temp.end());
          result.push_back(temp);
        }
      }
    }
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
  vector<vector<int> > result;
  sort(arr.begin(), arr.end());
  getSum(arr, result, k);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++)
      cout<<result[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
