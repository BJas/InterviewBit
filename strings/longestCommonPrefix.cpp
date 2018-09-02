#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<string>
using namespace std;
int main() {
  int n;
  cin>>n;
  string s[n];
  for(int i=0; i<n; i++)
    cin>>s[i];
  int minn = s[0].size();
  for(int i=1; i<n; i++){
    int len = s[i].size();
    minn = min(len, minn);
  }

  string res = "";
  int j = 0;
  while(j<minn) {
    char temp = s[0][j];
    for(int i=1; i<n; i++) {
        if(temp != s[i][j]) {
            cout<<res<<endl;
        }
    }
    res.push_back(temp);
    j++;
  }
  cout<<res;
  return 0;
}
