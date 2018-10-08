#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  vector<int> v;
  stack<int> st;
  for(int i=0; i<n; i++) {
    while(!st.empty() && st.top()>=a[i]) {
      st.pop();
    }
    if(st.empty()) {
      v.push_back(-1);
    } else {
      v.push_back(st.top());
    }
    st.push(a[i]);
  }
  for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
  return 0;
}
