#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int strToInt(string s) {
  int result = 0;
  int sign = 1;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='-') {
      sign = -1;
    } else if(s[i]=='+') {
      sign = 1;
    } else {
    result *= 10;
    result += s[i] - '0';
    }
  }
  return sign*result;
}
int main() {
  vector<string> A;
  int n;
  cin>>n;
  string s;
  for(int i=0; i<n; i++) {
    cin>>s;
    A.push_back(s);
  }
  stack<int> st;
  int first, second, numb;
  for(int i=0; i<n; i++) {
    if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/") {
      second = st.top();
      st.pop();
      first = st.top();
      st.pop();
      if(A[i] == "+")
          first += second;
      if(A[i] == "-")
          first -= second;
      if(A[i] == "*")
          first *= second;
      if(A[i] == "/")
          first /= second;
      st.push(first);
    } else {
      numb = strToInt(A[i]);
      st.push(numb);
    }
  }
  cout<<st.top();
  return 0;
}
