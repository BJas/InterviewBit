#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int lengthOfLast(string A) {
  int start = 0, len = 0, maxx = 0;
  while(start<A.size()) {
      if(A[start] == ' ') {
        len = 0;
      } else {
          len++;
      }
      if(len!=0)
        maxx = len;
      start++;
  }
  return maxx;
}
int main() {
  string s;
  cin>>s;
  int result = lengthOfLast(s);
  cout<<result;
  return 0;
}
