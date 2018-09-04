#include<iostream>
using namespace std;
int main() {
  string s;
  cin>>s;
  string res;
      string temp = "";
      for(int i=s.size()-1; i>=0; i--){
        if(s[i] == ' ') {
          if(temp.size() != 0) {
            reverse(temp.begin(), temp.end());
            res += temp;
            res += " ";
          }
          temp = "";
        } else {
          temp+=s[i];
        }
        if(i==0) {
          reverse(temp.begin(), temp.end());
          res+=temp;
        }
      }
      s = res;
  return 0;
}
