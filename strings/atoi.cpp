#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int atoi(string A) {
  int i=0, sign = 1;
  while(A[i]==' ') { i++; }
  if(A[i] == '-') sign = -1;
  if(A[i] == '-' || A[i] == '+') i++;
  long long result = 0;
  while(A[i]>='0' && A[i]<='9') {
    int digit = A[i] - '0';
    result *= 10;
    result += digit;
    if(sign*result<INT_MIN) return INT_MIN;
    if(sign*result>INT_MAX) return INT_MAX;
    i++;
  }
  return sign*result;
}
int main() {
  string s;
  cin>>s;
  int result = atoi(s);
  cout<<result;
  return 0;
}
