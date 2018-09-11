#include<iostream>
#include<climits>
using namespace std;
int swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
int partition(int a[], int low, int high) {
  int pivot = a[high];
  int p = low;
  for(int i=low; i<high; i++) {
    if(a[i]<pivot) {
      swap(&a[i], &a[p]);
      p++;
    }
  }
  swap(&a[p], &a[high]);
  return p;
}
void quickSort(int a[], int low, int high) {
  if(low<high) {
    int pivot = partition(a, low, high);
    quickSort(a, low, pivot-1);
    quickSort(a, pivot+1, high);
  }
}
int minXOR(int a[], int n) {
  int min = INT_MAX;
  int x;
  for(int i=0; i<n-1; i++) {
    x = a[i]^a[i+1];
    if(x<min) {
      min = x;
    }
  }
  return min;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  quickSort(a, 0, n-1);
  int result = minXOR(a, n);
  cout<<result;
  return 0;
}
