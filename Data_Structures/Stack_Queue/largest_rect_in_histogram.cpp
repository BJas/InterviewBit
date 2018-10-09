#include<iostream>
#include<stack>
using namespace std;
int getMax(int a[], int n) {
  stack<int> st;
  int i=0, maxArea = 0;
  while(i<n) {
    if(st.empty() || a[st.top()]<=a[i])
      st.push(i++);
    else {
      int top = st.top();
      st.pop();
      int w = st.empty() ? i : i-st.top()-1;
      if(maxArea<a[top]*w)
        maxArea = a[top]*w;
    }
  }
  while(!st.empty()) {
    int top = st.top();
    st.pop();
    int w = st.empty() ? i : i-st.top()-1;
    if(maxArea<a[top]*w)
      maxArea = a[top*w];
  }
  return maxArea;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int result = getMax(a, n);
  cout<<result;
  return 0;
}
