#include<iostream>
using namespace std;
int main() {
  string s;
  cin>>s;
  string res;
  string temp = "";
  for(int i=0; i<s.size(); i++){
    if(s[i] == ' ') {
      if(!temp.empty())
        res += temp + " ";
      temp = "";
    } else {
      temp+=s[i];
    }
    if(i==s.size()-1)
      res+=temp;
  }
  cout<<res;
  return 0;
}
