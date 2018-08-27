#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void sieveEratosthene(int n) {
  vector<int> a(n+1, 1);
  for(int i=2; i<=sqrt(n); i++) {
    if(a[i] == 1) {
      for(int j=i*i; j<=n; j+=i)
        a[j] = 0;
    }
  }
  for(int i=1; i<=n; i++)
    if(a[i] == 1)
      cout<<i<<" ";
}
int main() {
  int n;
  cin>>n;
  sieveEratosthene(n);
}
