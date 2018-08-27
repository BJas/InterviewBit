#include <iostream>
using namespace std;
void pascalTriangle(int n) {
  int a[n][n];
  int i=0, m=1;
  while(i<n) {
    a[i][0] = 1;
    a[i][m-1] = 1;
    for(int j=1; j<m-1; j++) {
          a[i][j] = a[i-1][j] + a[i-1][j-1];
    }
    i++;
    m++;
  }
  int t=1;
  for(int i=0; i<n; i++) {
      for(int j=0; j<t; j++) {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
      t++;
  }
}
int main() {
  int n;
  cin>>n;
  pascalTriangle(n);
  return 0;
}
