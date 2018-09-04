#include<iostream>
using namespace std;
int searchInsert(int A[], int n, int x) {
  int left = 0, right = n-1;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(A[mid] == x) return mid;
    else if(A[mid]>x) right = mid-1;
    else left = mid+1;
  }
  return left;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int x;
  cin>>x;
  int result = searchInsert(a, n, x);
  cout<<result;
  return 0;
}
