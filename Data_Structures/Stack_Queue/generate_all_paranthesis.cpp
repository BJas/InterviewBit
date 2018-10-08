#include<iostream>
#include<stack>
using namespace std;
int main() {
  string s;
  cin>>s;
  stack<char> st;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    } else {
      if(!st.empty() && ((s[i]=='}' && st.top() == '{') || (s[i]==')' && st.top() == '(') || (s[i]==']' && st.top() == '[]')))
        st.pop();
      else
        cout<<0;
    }
  }
  if(!st.empty()) cout<<0;
  cout<<1;
  return 0;
}
