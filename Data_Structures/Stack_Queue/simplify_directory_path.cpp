#include<iostream>
#include<stack>
using namespace std;
int main() {
  string s;
  cin>>s;
  stack<string> st;
  int i=0;
  while(i<s.size()) {
    if(s[i] == '/') i++;
    else if(s[i] == '.') {
      if(i!=s.size()-1 && s[i+1]=='.' && !st.empty()) {
        st.pop();
        i+=2;
      }
      else
        i++;
    } else {
      string str = "";
      while(i <s.size() && (s[i]!='.' || s[i]!='/')) {
        str += s[i];
        cout<<s[i]<<endl;
        i++;
      }
      st.push(str);
    }
  }
  if(st.empty()) cout<<"/";
  string res = "";
  while(!st.empty()) {
    res += st.top();
    res += "/";
    st.pop();
  }
  cout<<res;
  return 0;
}
