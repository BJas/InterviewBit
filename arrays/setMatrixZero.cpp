#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>a[i][j];
    }
  }
  vector<int> row(n, 0), col(n, 0);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(a[i][j] == 0) {
        row[i]++;
        col[j]++;
      }
    }
  }
  int i=0;
  while(i<n) {
    if(row[i]>0) {
      for(int j=0; j<n; j++)
        a[i][j] = 0;
    }
    if(col[i]>0) {
      for(int j=0; j<n; j++)
        a[j][i] = 0;
    }
    i++;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout<<a[i][j]<<" ";
    }
     cout<<endl;
  }
  return 0;
}
