#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int getPalindrome(string s) {
  int start = 0, end = s.size()-1, size = s.size(), len = s.size()-1;
  while(start<=end){
    if(s[start] == s[end]) {
      start++;
      end--;
    } else {
      start=0;
      end = len--;
    }
  }
  return A.size()-(end+1);
}
int main() {
  string s;
  cin>>s;
  int result2 = getPalindrome(s);
  cout<<result2;
  return 0;
}
