#include<iostream>
using namespace std;
string longestPalindrome(string s) {
  int maxLen = 1, start = 0, low, high;
  for(int i=0; i<s.size(); i++){
    low = i-1;
    high = i;
    while(low>=0 && high<s.size() && s[low]==s[high]) {
      if(high-low+1>maxLen) {
        maxLen = high - low + 1;
        start = low;
      }
      low--;
      high++;
    }
    low = i-1;
    high = i+1;
    while(low>=0 && high<s.size() && s[low]==s[high]) {
      if(high-low+1>maxLen) {
        maxLen = high - low + 1;
        start = low;
      }
      low--;
      high++;
    }
  }
  string result;
  for(int i=start; i<start+maxLen; i++)
    result.push_back(s[i]);

  return result;
}
int main() {
  string str;
  cin>>str;
  string result = longestPalindrome(str);
  cout<<result;
  return 0;
}
