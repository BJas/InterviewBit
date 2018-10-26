#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main() {
  int numerator, denomin;
  cin>>numerator>>denomin;
  double d = numerator/denomin;
  int sign = d > 0.0 ? 1 : -1;
  if(numerator<0)
    numerator *= -1;
  if(denomin<0)
    denomin *= -1;
  long long rem = numerator%denomin, i=0;
  map<long long, int> m;
  string str = "";
  while(rem!=0 && m.find(rem)==m.end()) {
    m[rem] = i;
    rem *= 10;
    int result = rem/denomin;
    char ch = result + '0';
    str += ch;
    rem %= denomin;
    i++;
  }
  string s = "";
  if(sign==-1)
    s = "-";
  s += to_string(numerator/denomin);
  if(rem==0) {
    if(numerator%denomin!=0) {
      s += '.';
      s += str;
    }
  } else {
    s += '.';
    for(int j=0; j<m[rem]; j++) {
      s += str[j];
    }
    s += '(';
    for(int j=m[rem]; j<i; j++) {
      s += str[j];
    }
    s += ')';
  }
  cout<<s;

  return 0;
}
