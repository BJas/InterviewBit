#include<iostream>
using namespace std;
int main() {
  string s;
  cin>>s;
  int ind = 0;
  int col=0;
  while(ind<s.size()) {
    if(col!=0) col *=26;
    col += (int)s[ind]-64;
    ind++;
  }
  cout<<col;
  return 0;
}
