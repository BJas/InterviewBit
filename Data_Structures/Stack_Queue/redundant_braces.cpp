#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
  string s;
  cin>>s;
  stack<char> st;
  int op = 0, cnt = 0;
  for(int i=0; i<s.size(); i++) {
    if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
      st.push(s[i]);
      op++;
    }
    if(s[i] == '(' || s[i] == ')') {
      if(!st.empty() && (s[i] == ')' && st.top() == '('))
        cout<<1;
      if(s[i] == '(')
          cnt++;
      st.push(s[i]);
    }
  }
  if(op<cnt)
    cout<<1;
  cout<<0;
  return 0;
}
