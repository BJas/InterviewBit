#include<iostream>
using namespace std;
string zigzag(string s, int n) {
  if(n==1) return s;
  string result;
  for(int i=0; i<n; i++) {
    int j=i, check = 0;
    while(j<s.size()) {
      result += s[j];
      if(check%2==0) {
        int rem = i%(n-1);
        j += (n-rem-2)*2+2;
      }
      else {
        int rem = (n-1-i)%(n-1);
        j += (n-rem-2)*2+2;
      }
      check++;
    }
  }
  return result;
}
int main(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  string result = zigzag(s, n);
  cout<<result;
  return 0;
}
