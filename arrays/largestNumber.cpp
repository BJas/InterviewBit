#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;
    void heapify(int a[], int n, int i){
   int largest = i;
      int left = 2*i+1;
      int right = 2*i+2;

      int l = to_string(a[largest]).size();
      int k = to_string(a[left]).size();
      int r = to_string(a[right]).size();

      if(left<n && a[left]*pow(10,l)+a[largest] > a[largest]*pow(10,k)+a[left])
        largest = left;

      l = to_string(a[largest]).size();

      if(right<n && a[right]*pow(10,l)+a[largest] > a[largest]*pow(10,r)+a[right])
        largest = right;

      if(largest != i) {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
      }
}
void largestNumber(int a[], int n){
    for(int i=n/2-1; i>=0; i--)
        heapify(a, n, i);
    for(int i=n-1; i>=0; i--) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a, i, 0);
    }
  string s = "";
  for(int i=n-1; i>=0; i--) {
    ostringstream str1;
    str1 << a[i];
    s += str1.str();
  }
  cout<<s;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  largestNumber(a, n);
  return 0;
}
