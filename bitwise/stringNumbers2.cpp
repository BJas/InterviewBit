#include<iostream>
#include<cmath>
using namespace std;
int singleNumber(int A[], int n) {
  int result = 0;
  for(int i=0; i<32; i++) {
    int cnt = 0;
    for(int j=0; j<n; j++) {
       if((A[j]&(1<<i))>>i == 1)
        cnt++;
    }
    if(cnt%3==1)
      result += 1*pow(2,i);
  }
  return result;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int result = singleNumber(a, n);
  cout<<result;
  return 0;
}
