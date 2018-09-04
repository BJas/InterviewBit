#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int isPowerOfTwo(string n) {
  if(n == "1") return 0;
  int result = n[n.size()-1] - '0';
  while(result%2 != 1) {
    int rem = 0, number = 0;
    string res;
    for(int i=0; i<n.size(); i++) {
        number = rem*10+ n[i] - '0';
        rem = number%2;
        char ch = number/2 + '0';
        res += ch;
    }

    if(res[0] == '0') n = res.substr(1, res.size()-1);
    else n = res;
    result = res[res.size()-1] - '0';
  }
  if(n == "1") return 1;
  return 0;
}
int main() {
  string n;
  cin>>n;
  int result = isPowerOfTwo(n);
  cout<<result;
  return 0;
}
