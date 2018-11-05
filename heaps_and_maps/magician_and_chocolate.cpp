#include<iostream>
#include<vector>
using namespace std;
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
void heapify(vector<int> &v, int i, int n) {
  int largest = i;
  int left = i*2+1;
  int right = i*2+2;
  if(left<n && v[left]>v[largest])
    largest = left;
  if(right<n && v[right]>v[largest])
    largest = right;
  if(largest!=i) {
    swap(&v[largest], &v[i]);
    heapify(v, largest, n);
  }
}
int main() {
  int n, x, k;
  cin>>n;
  vector<int> v;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x);
  }
  cin>>k;
  for(int i=n/2-1; i>=0; i--)
    heapify(v, i, n);
  int result = 0;
  for(int i=0; i<k; i++) {
    result += v[0];
    v[0] = v[0]/2;
    heapify(v, 0, n);
  }
  cout<<result;
  return 0;
}
