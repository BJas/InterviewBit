#include<iostream>
using namespace std;
int main() {
  int a, b;
  cin>>a>>b;
  int res[a][b];
  for(int i=0; i<a; i++)
    res[i][0] = 1;
  for(int j=0; j<b; j++)
    res[0][j] = 1;

  for(int i=1; i<a; i++) {
    for(int j=1; j<b; j++) {
      res[i][j] = res[i-1][j] + res[i][j-1];
    }
  }
  cout<<res[a-1][b-1];
  return 0;
}
