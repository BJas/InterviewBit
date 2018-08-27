#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<int> a;
  vector<int> b;
  for(int i=1; i<=sqrt(n); i++) {
    if(n%i == 0) {
      a.push_back(i);
      if(i!=sqrt(n))
        b.push_back(n/i);
    }
  }
  reverse(b.begin(), b.end());
  for(int i=0; i<a.size(); i++)
    cout<<a[i]<<" ";
  for(int i=0; i<b.size(); i++)
    cout<<b[i]<<" ";
  return 0;
}
