#include<iostream>
using namespace std;
int findElement(int a[], int n, int x) {
  int left = 0, right = n-1;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(a[mid] == x) return mid;
    else if (A[mid]<=A[high])
    {
      if(x>A[mid] && x<=A[high])
        left = mid+1;
      else
        right = mid-1;
    }
    else
    {
      if(x>=A[left] && x< A[mid])
        right = mid-1;
      else
        left = mid+1;
    }
  }
  return -1;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int x;
  cin>>x;
  int result = findElement(a, n, x);
  cout<<result;
  return 0;
}
