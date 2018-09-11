#include<iostream>
using namespace std;
int getDifferentBit(int a[], int n) {
  int temp, result = 0;
  for(int i=0; i<32; i++) {
    temp = 1<<i;
    int cnt = 0;
    for(int j=0; j<n; j++) {
      if(a[j]&temp) {
        cnt++;
      }
    }
    result += cnt*(n-cnt);
  }
  return result*2;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int result = getDifferentBit(a, n);
  cout<<result;
  return 0;
}
