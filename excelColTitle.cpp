#include<iostream>
#include<string>
using namespace std;
int main() {
  int a;
  cin>>a;
  string res;
  while(a>0) {
    int rem = a%26;
    if(rem == 0) {
      res+="Z";
      a/=26;
      a--;
    }
    else {
      res+=rem+64;
      a/=26;
    }
  }
  reverse(res.begin(), res.end());
  cout<<res;
  return 0;
}
