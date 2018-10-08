#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char ch) {
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    return true;
  return false;
}
bool hasHigherPrecedence(char op, char op2) {
  if(op == '*' || op == '/') {
    if(op2 == '+' || op2 == '-')
      return true;
  }
  return false;
}
int main() {
  string s;
  cin>>s;
  string res;
  stack<char> st;
  for(int i=0; i<s.size(); i++) {
    if(isOperator(s[i])) {
      while(!st.empty() && hasHigherPrecedence(st.top(), s[i]) && st.top() != '(') {
        res += st.top();
        st.pop();
      }
      st.push(s[i]);
    } else if(s[i] == '(') {
      st.push(s[i]);
    } else if(s[i] == ')') {
       while(!st.empty() && st.top() != '(') {
         res += st.top();
         st.pop();
       }
       st.pop();
    }
    else {
      res += s[i];
    }
  }
  while(!st.empty()) {
    res += st.top();
    st.pop();
  }
  cout<<res;
  return 0;
}
