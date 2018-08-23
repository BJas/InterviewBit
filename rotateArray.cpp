#include<iostream>
using namespace std;
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
int main(){
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        cin>>a[i][j];
    }
  }

  for(int i=0; i<n/2; i++) {
    for(int j=0; j<n; j++) {
        swap(&a[i][j], &a[n-i-1][j]);
    }
  }

  int i=0;

  while(i<n) {
     for(int j=i; j<n; j++) {
         swap(&a[i][j], &a[j][i]);
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
