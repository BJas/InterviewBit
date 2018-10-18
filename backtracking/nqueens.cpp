#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool isAttacked(int n, vector<string> &nqueen, int row, int col) {
  for(int i=0; i<col; i++)
    if(nqueen[row][i]=='Q')
      return false;

  for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    if(nqueen[i][j]=='Q')
      return false;

  for(int i=row, j=col; i<n && j>=0; i++, j--)
    if(nqueen[i][j]=='Q')
      return false;

  return true;
}
bool backtracking(int n, vector<vector<string> > &result, vector<string> &nqueen, int col) {
  if(col == n) {
    result.push_back(nqueen);
    return false;
  }
  for(int i=0; i<n; i++) {
    if(isAttacked(n, nqueen, i, col)) {
      nqueen[i][col] = 'Q';
      if(backtracking(n, result, nqueen, col+1))
        return true;
      nqueen[i][col] = '.';
    }
  }
  return false;
}
int main() {
  int n;
  cin>>n;
  vector<vector<string> > result;
  vector<string> nqueen;
  string temp;
  for(int i=0; i<n; i++) {
    temp = "";
    for(int j=0; j<n; j++) {
      temp += '.';
    }
    nqueen.push_back(temp);
  }
  backtracking(n, result, nqueen, 0);
  cout<<"Result:\n";
  for(int i=0; i<result.size(); i++) {
    cout<<"List is:\n";
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<endl;
    }
    cout<<endl;
  }
  return 0;
}
