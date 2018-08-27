#include <iostream>
using namespace std;
void spiral(int n) {
  int sR = 0, eR = n-1, sC = 0, eC = n-1, counter = 1;
  int a[n][n];
  while(counter<=n*n) {
    for(int j=sR; j<=eR; j++) {
      a[sC][j] = counter;
      counter++;
    }
    sC++;

    for(int i=sC; i<=eC; i++) {
      a[i][eR] = counter;
      counter++;
    }
    eR--;

    for(int j=eR; j>=sR; j--) {
      a[eC][j] = counter;
      counter++;
    }
    eC--;

    for(int i=eC; i>=sC; i--) {
      a[i][sR] = counter;
      counter++;
    }
    sR++;
  }

  for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         cout<<a[i][j]<<" ";
      }
      cout<<endl;
  }
}
int main() {
  int n;
  cin>>n;
  spiral(n);
  return 0;
}
