#include<iostream>
#include<algorithm>
using namespace std;
int check(int sum, int rem) {

}
string addBinary(string A, string B) {
  string res = "";
  int i = A.size()-1, j = B.size()-1, rem = 0, sum;
  int maxx = max(i, j);
  while(maxx>=0) {
    if(i>=0 && j>=0)
      sum = (A[i] - '0') + (B[j] - '0') + rem;
    else if(i>=0)
      sum = (A[i] - '0') + rem;
    else
      sum = (B[j] - '0') + rem;
    rem = sum/2;
    sum %= 2;
    res += sum + '0';
    i--;
    j--;
    maxx--;
  }
  if(rem == 1) res += rem + '0';
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  string A, B;
  cin>>A>>B;
  string result = addBinary(A, B);
  cout<<result;
  return 0;
}
