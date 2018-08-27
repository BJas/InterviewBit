#include<iostream>
#include<cmath>
using namespace std;
void primeFactors(int number) {
  for(int i=2; i<=sqrt(number); i++) {
    if(number%i==0) {
      int counter=0;
      while(number%i==0) {
        number /= i;
        counter++;
      }
      cout<<i<<" exp: "<<counter<<endl;
    }
  }
  if(number!=1) cout<<number<<" exp: "<<1<<endl;
}
int main() {
  int number;
  cin>>number;
  primeFactors(number);
  return 0;
}
