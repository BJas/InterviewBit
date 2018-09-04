#include<iostream>
using namespace std;
int rotateNumber(int a[], int n) {
  int low = 0, high = n-1;
  while(low<=high) {
    int mid = low + (high-low)/2;
    if(a[low]<=a[high]) return low;
    if(a[mid]<a[(mid+1)%n] && a[mid]<a[(mid-1+n)%n]) {
      return mid;
    } else if(a[mid]<=a[high]) {
      high = mid-1;
    } else if(a[mid]>=a[low]) {
      low = mid+1;
    }
  }
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  int result = rotateNumber(a, n);
  cout<<result;
  return 0;
}
