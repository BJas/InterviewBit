#include<iostream>
#include<algorithm>
using namespace std;
string countAndSay(int n) {
  string res = "1";
  for(int i=0; i<n-1; i++) {
    int j=0, count = 1, last = res[0] - '0';
    string temp = "";
    while(j<res.size()) {
      int t = res[j] - '0';
      if(last == t)
        if(j==0)
          count=1;
        else
          count++;
      else {
        char c = count + '0';
        char l = last + '0';
        temp += c;
        temp += l;
        last = t;
        count = 1;
      }
      if(j+1==res.size()) {
        char c = count + '0';
        char l = last + '0';
        temp += c;
        temp += l;
        break;
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
