#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main() {
  int n, x;
  cin>>n;
  vector<vector<int> > v;
  for(int i=0; i<n; i++) {
    vector<int> temp;
    for(int j=0; j<2; j++) {
      cin>>x;
      temp.push_back(x);
    }
    v.push_back(temp);
  }

  map<double, int> m;
  int maxLen = 0;
  for(int i=0; i<v.size(); i++) {
    int vertical = 0, duplicated = 1;
    for(int j=i+1; j<v.size(); j++) {
      if(v[i][0]==v[j][0]) {
        if(v[i][1]==v[i][1]) {
          duplicated++;
        } else {
          vertical++;
        }
      } else {
        double slope = (v[i][1]-v[j][1])*1.0/(v[i][0]-v[j][0])*1.0;
        if(m.find(slope)!=m.end()) {
          m[slope]++;
        } else {
          m[slope] = 1;
        }
      }
    }
    for(auto itr = m.begin(); itr!=m.end(); itr++) {
      if(itr->second + duplicated > maxLen) {
        maxLen = itr->second + duplicated;
      }
    }
    if(vertical + duplicated > maxLen) {
      maxLen = vertical + duplicated;
    }
    m.clear();
  }
  cout<<maxLen;
  return 0;
}
