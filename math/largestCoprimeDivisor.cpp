#include<iostream>
using namespace std;
int gcd(int first, int second) {
  return first == 0 : second ? gcd(first, second%first);
}
int main() {
  int divident;
  cin>>divident;
  int numberToGCD;
  cin>>numberToGCD;
  while (gcd(divident, numberToGCD) != 1) {
        divident = divident / gcd(divident, numberToGCD);
    }
  cout<<divident;
  return 0;
}
