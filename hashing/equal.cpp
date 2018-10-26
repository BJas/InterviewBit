#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int > getEqual(vector<int> &A) {
  vector<vector<int> > result;
  map<int, pair<int,int> > m;
  for(int i=0; i<A.size()-1; i++) {
    for(int j=i+1; j<A.size(); j++) {
      int sum = A[i]+A[j];
      if(m.find(sum)!=m.end()) {
        pair<int, int> x = m[sum];
        if(x.first!=i && x.first!=j
           && x.second!=i && x.second!=j) {
             vector<int> temp;
             temp.push_back(x.first);
             temp.push_back(x.second);
             temp.push_back(i);
             temp.push_back(j);
             result.push_back(temp);
           }
      } else {
        m[A[i]+A[j]] = make_pair(i, j);
      }
    }
  }
  sort(result.begin(), result.end());
  return result[0];
}
int main() {
  int n, x;
  cin>>n;
  vector<int> v;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x);
  }
  vector<int> result;
  result = getEqual(v);
    for(int j=0; j<result.size(); j++) {
      cout<<result[j]<<" ";
    }
  return 0;
}
