#include<iostream>
using namespace std;
int firstOccurance(int a[], int n, int x) {
  int left = 0, right = n-1, result = -1;
  while(left<=right) {
    int mid = (left+right)/2;
    if(a[mid] == x) {
      result = mid;
      right = mid - 1; //to get last occur: left = mid + 1;
    } else if(a[mid] > x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
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
  int result = firstOccurance(a, n, x);
  cout<<result;
  return 0;
}
