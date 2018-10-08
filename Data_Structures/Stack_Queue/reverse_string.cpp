#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
void reverse(char s[], int len) {
  stack<char> st;
  for(int i=0; i<len; i++) {
    st.push(s[i]);
  }
  for(int i=0; i<len; i++) {
    s[i] = st.top();
    st.pop();
  }
  printf("%s", s);
}
int main() {
  char s[101];
  scanf("%s", s);
  reverse(s, strlen(s));
  return 0;
}
