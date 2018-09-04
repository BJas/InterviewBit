#include<iostream>
#include<algorithm>
using namespace std;
string countAndSay(int n) {
  if(n==1) return "1";
  if(n==2) return "11";
  string res = "1";
  for(int i=1; i<n; i++) {
    res += "$";
    int j=1, count = 1;
    string temp = "";
    while(j<res.size()) {
      int t = res[j] - '0';
      if(res[j]==res[j-1])
          count++;
      else {
        char c = count + '0';
        temp += c;
        temp += res[j-1];
        count = 1;
      }
      j++;
    }
    res = temp;
  }
  return res;
}
int main() {
  int n;
  cin>>n;
  string str = countAndSay(n);
  cout<<str;
  return 0;
}
