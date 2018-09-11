#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int divide(int a, int b) {
  if(a>INT_MAX || b>INT_MAX) return INT_MAX;
  long long A = a;
  long long B = b;
  int temp = 0;
  long long result = 0;
  int sign = ((A < 0)^(B < 0)) ? -1 : 1;
  A = abs(A);
  B = abs(B);
  for(int i=31; i>=0; i--) {
    if(temp + (B << i) <= A) {
      temp += B << i;
      result |= 1LL << i;
    }
  }
  return sign*result;
}
int main() {
  int a, b;
  cin>>a>>b;
  int result = divide(a, b);
  cout<<result;
  return 0;
}
