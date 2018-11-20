#include<iostream>
#include<stack>
using namespace std;
bool isOpen(char paranthesis) {
  switch (paranthesis) {
    case '{':
      return true;
    case '(':
      return true;
    case '[':
      return true;
  }
  return false;
}
bool isCorrect(char opening, char closing) {
  if(opening == '{' && closing == '}')
    return true;
  if(opening == '[' && closing == ']')
    return true;
  if(opening == '(' && closing == ')')
    return true;
  return false;
}
int generateAllParanthesis(string s) {
  stack<char> st;
  for(int i=0; i<s.length(); i++) {
    if(isOpen(s[i]))
      st.push(s[i]);
    else {
      if(!st.empty() && isCorrect(st.top(), s[i]))
        st.pop();
      else
        return 0;
    }
  }
  return st.empty();
}
int main() {
  string s;
  cin>>s;
  cout<<generateAllParanthesis(s);
  return 0;
}
