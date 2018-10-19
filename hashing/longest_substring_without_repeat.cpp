#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main() {
  string str;
  cin>>str;
  map<char, bool> m;
  int i=0, j=0, max_len = 0, temp = 0;
  while(j<str.size()) {
    if(m.find(str[j]) != m.end()) {
      while(str[i]!=str[j]) {
        m.erase(str[i]);
        i++;
        temp--;
      }
      if(i != j) {
        i++;
      }
      temp--;
      m.erase(str[j]);
    } else {
      m[str[j]] = true;
      temp++;
      j++;
    }
    if(max_len<temp) {
      max_len = temp;
    }
  }
  cout<<max_len;
}
