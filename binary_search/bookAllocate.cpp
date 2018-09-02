#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
bool isPossible(int a[], int n, int m, int mid) {
  int sum = 0, noOfStudents = 1;
  for(int i=0; i<n; i++) {
    if(a[i]>mid)
      return false;
    if(a[i]+sum > mid) {
      noOfStudents++;
      sum = a[i];
      if(noOfStudents>m)
        return false;
    } else {
      sum+=a[i];
    }
  }
  return true;
}
int bookAllocate(int a[], int n, int m) {
  int sum_of_pages = 0;
  for(int i=0; i<a[i]; i++)
    sum_of_pages += a[i];
  if(n<m) return -1;
  int left = 0, right = sum_of_pages, result = INT_MAX;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(isPossible(a, n, m, mid)) {
      result = min(result, mid);
      right = mid-1;
    } else {
      left = mid+1;
    }
  }
  return result;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int m;
  cin>>m;
  int result = bookAllocate(a, n, m);
  cout<<result;
  return 0;
}
