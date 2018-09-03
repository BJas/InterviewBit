#include<iostream>
using namespace std;
int countOfOccurance(int a[], int n, int x, bool isFirst) {
  int left = 0, right = n-1, first = -1;
  while(left<=right) {
    int mid = left + (right-left)/2;
    if(a[mid] == x) {
      first = mid;
      if(isFirst)
        right = mid-1;
      else
        left = mid+1;
    } else if(a[mid] > x)
      right = mid-1;
      else
      left = mid+1;
  }
  return first;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  int x;
  cin>>x;
  int first = countOfOccurance(a, n, x, true);
  int last = countOfOccurance(a, n, x, false);
  cout<< last-first+1;
  return 0;
}
