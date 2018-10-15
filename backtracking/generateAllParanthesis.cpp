#include<iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;
void getParanthesis(int n, vector<string> &result, string current, int open, int close, int index) {
  if(index==2*n) {
    result.push_back(current);
    return;
  }
  if(open<n){
    cout<<"push1"<<endl;
    current += '(';
    getParanthesis(n, result, current, open+1, close, index+1);
    cout<<"pop1"<<endl;
    // current.pop_back();
  }
  if(open>close) {
     cout<<"push2"<<endl;
    current += ')';
    getParanthesis(n, result, current, open, close+1, index+1);
    cout<<"pop2"<<endl;
    // current.pop_back();
  }
}
int main() {
  int n;
  cin>>n;
  vector<string> result;
  string current = "";
  getParanthesis(n, result, current, 0, 0, 0);
  cout<<"Result is:\n";
  for (int i=0; i<result.size(); i++) {
    cout<<result[i]<<" ";
  }
  return 0;
}
