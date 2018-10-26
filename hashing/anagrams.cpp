#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
  int n;
  cin>>n;
  string x;
  vector<string> str;
  for(int i=0; i<n; i++) {
    cin>>x;
    str.push_back(x);
  }
  unordered_map<string, vector<int> > m;
  for(int i=0; i<n; i++) {
    x = str[i];
    sort(x.begin(), x.end());
    m[x].push_back(i+1);
  }
  vector<vector<int> > result;
  unordered_map<string, vector<int> >::iterator it;
  for(it=m.begin(); it!=m.end(); it++) {
    result.push_back(it->second);
  }
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
