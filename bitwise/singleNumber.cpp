#include<iostream>
#include<cmath>
using namespace std;
int singleNumber(int a[], int n) {
  int result = 0;
   for(int i=0; i<n; i++) {
     result ^= a[i];
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
