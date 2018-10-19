#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
bool isColorful(int n) {
  map<int, bool> subsequence;
  string subset = to_string(n);
  int prod, j;
  for(int i=0; i<subset.size(); i++) {
     j = i;
     prod = 1;
    while(j<subset.size()) {
      prod *= subset[j] - '0';
      if(subsequence.find(prod) != subsequence.end())
        return false;
      subsequence[prod] = true;
      j++;
    }
  }
  return true;
}
int main() {
  int n;
  cin>>n;
  bool result = isColorful(n);
  cout<<result;
  return 0;
}
