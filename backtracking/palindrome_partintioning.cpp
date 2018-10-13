#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
bool isPalindrome(string s) {
  int i=0, j=s.size()-1;
  while(i<j) {
    if(s[i]!=s[j])
      return false;
    i++;
    j--;
  }
  return true;
}
void getPalindrome(string s, vector<string> &subset, vector<vector<string> > &result, int index) {
  if(index==s.size()) {
    result.push_back(subset);
    return;
  }
  string current = "";
  for(int i=index; i<s.size(); i++)  {
    current += s[i];
    if(isPalindrome(current)) {
      subset.push_back(current);
      printf("Subset:\n");
      for (size_t i = 0; i < subset.size(); i++) {
        cout<<subset[i]<<" ";
      }
      printf("\n");
      getPalindrome(s, subset, result, i+1);
      printf("Pops\n");
      subset.pop_back();
    }
  }
}
int main() {
  string s;
  cin>>s;
  vector<string> subset;
  vector<vector<string> > result;
  getPalindrome(s, subset, result, 0);
  cout<<"Result is:\n";
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
