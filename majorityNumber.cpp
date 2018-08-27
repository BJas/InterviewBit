#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  int counter = 0, first = INT_MAX;
  for(int i=0; i<n; i++) {
    if(a[i] == first) {
      counter++;
    } else if(counter == 0) {
      first = a[i];
      counter++;
    } else {
      counter--;
    }
  }
  cout<<first<<endl;
  return 0;
}
