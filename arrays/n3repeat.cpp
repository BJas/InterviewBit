#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];

  int first=INT_MAX, second=INT_MAX, counter=0, counter2=0;
  for(int i=0; i<n; i++) {
    if(a[i] == first)
      counter++;
    else if(a[i] == second)
      counter2++;
    else if(counter == 0) {
      first = a[i];
      counter++;
    }
    else if(counter2 == 0) {
      second = a[i];
      counter2++;
    }
    else {
      counter--;
      counter2--;
    }
  }
  counter=0, counter2=0;
  for(int i=0; i<n; i++) {
    if(a[i] == first)
      counter++;
    if(a[i] == second)
      counter2++;
  }
  if(counter>n/3) cout<<first;
  if(counter2>n/3) cout<<second;
  return 0;
}
