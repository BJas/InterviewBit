#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n) {
  for(int i=2; i<=sqrt(n); i++) {
    if(n%i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin>>n;
  bool res = isPrime(n);
  cout<<res<<endl;
  return 0;
}
