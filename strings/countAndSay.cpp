#include<iostream>
using namespace std;
string countAndSay(int n) {
  string res = "1";
  for(int i=0; i<n; i++) {
    int j = 0, last = -1, count = 1;
    string temp = "";
    while(j<res.size()) {
      int number = res[j] - '0';
      if(last == number)
        count++;
      else if(last != -1) {
        char l = number + '0';
        char c = count + '0';
        temp += l;
        temp += c;
        count = 1;
      }
      last = number;
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
