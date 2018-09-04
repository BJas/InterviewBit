#include<iostream>
using namespace std;
// string intToRoman(int num) {   ///Best solution
//         // 1000, 2000, 3000
//         string M[] = {"", "M", "MM", "MMM"};
//         // 100, 200, 300, .. 900
//         string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//         // 10, 20, ... 90
//         string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//         // 1, 2, ... 9
//         string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//         return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
// }
string repeat(int rem, string roman) {
  string result = "";
  for(int i=0; i<rem; i++)
    result += roman;
  return result;
}
string toRoman(int rem) {
  string res = "";
  if(rem>0 && rem<4) res += repeat(rem, "I");
  else if(rem == 4) res += "VI";
  else if(rem>4 && rem<9) {
    res += repeat(rem%5, "I");
    res += "V";
  }
  else if(rem == 9) res += "XI";
  else if(rem>9 && rem<40) res += repeat(rem/10, "X");
  else if(rem>=40 && rem<50) res += "LX";
  else if(rem>=50 && rem <90) {
    res += repeat((rem/10)%5, "X");
    res += "L";
  }
  else if(rem >= 90 && rem < 100) res += "CX";
  else if(rem>=100 && rem<400) res += repeat(rem/100, "C");
  else if(rem>=400 && rem<500) res += "DC";
  else if(rem>=500 && rem <900) {
    res += repeat((rem/100)%5, "C");
    res += "D";
  }
  else if(rem >= 900 && rem < 1000) res += "MC";
  else if(rem>=1000 && rem<=4000) res += repeat(rem/1000, "M");
  return res;
}
string intToRoman(int n) {
  int mod = 10;
  string res = "";
  while(mod<=n*10) {
    int rem = n%mod;
    if(mod/10<=rem)res += toRoman(rem);
    mod *= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  int n;
  cin>>n;
  string result = intToRoman(n);
  cout<<result;
  return 0;
}
