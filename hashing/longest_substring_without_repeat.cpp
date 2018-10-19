#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main() {
  string str;
  cin>>str;
  map<char, int> m;
  int max_len = 0, len = 0, left = 0;
  for(int i=0; i<str.size(); i++) {
    if(m.find(str[i])!=m.end()) {
      if(len>max_len)
        max_len = len;
      len = i - left;
      left = i;
    } else {
      m[str[i]] = i;
      len++;
    }
  }
  cout<<max(len, max_len);
}
