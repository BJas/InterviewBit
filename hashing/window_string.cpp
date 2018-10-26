#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;
int main() {
  string str, pattern;
  cin>>str>>pattern;
  map<char, int> p;
  for(int i=0; i<pattern.size(); i++)
    p[pattern[i]]++;
  map<char, int> s;
  int count = 0, start = 0, minLen = INT_MAX, left = 0;
  for(int i=0; i<str.size(); i++) {
    s[str[i]]++;

    if(p[str[i]]!=0 && s[str[i]]<=p[str[i]])
      count++;

    if(count==pattern.size()) {

      while(s[str[start]] > p[str[start]] || s[str[start]] == 0) {
        if(s[str[start]]>p[str[start]])
          s[str[start]]--;
        start++;
      }
      if(minLen>i-start+1) {
        minLen = i-start+1;
        left = start;
      }
    }
  }
  for(int i=left; i<left+minLen; i++)
    cout<<str[i];
  return 0;
}
