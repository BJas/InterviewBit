#include<iostream>
#include<climits>
using namespace std;
int sqrt(int A) {
   int left = 1, right = A;
      while(left<=right) {
        long long mid = left+(right-left)/2;
        if(mid*mid == A || ((mid+1)*(mid+1)>A && mid*mid<A)) return mid;
        else if(mid*mid < A)
          left = mid+1;
        else
          right = mid-1;
      }
  return 0;
}
int main() {
  int n;
  cin>>n;
  int result = sqrt(n);
  cout<<result;
  return 0;
}
