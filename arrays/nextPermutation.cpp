#include<iostream>
using namespace std;
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
int partition(int A[], int l, int r) {
  int ind = l;
  int ind_num = A[r];
  for(int i=l; i<r; i++) {
    if(A[i]<ind_num) {
      swap(&A[i], &A[ind]);
      ind++;
    }
  }
  swap(&A[ind], &A[r]);
  return ind;
}
void sort(int A[], int l, int r) {
  if(l<r) {
    int part = partition(A, l, r);
    sort(A, l, part-1);
    sort(A, part+1, r);
  }
}
int main() {
  int n;
  cin>>n;
  int A[n];
  for(int i=0; i<n; i++) {
    cin>>A[i];
  }
  int last=A[n-1];
  int i=n-2;
  while(i>=0){
    if(A[i]<last)
      break;
    i--;
  }
  if(i+1!=0) swap(A[i], A[n-1]);
  sort(A, i+1, n-1);
  for(int i=0; i<n; i++) {
    cout<<A[i]<<" ";
  }
  return 0;
}
