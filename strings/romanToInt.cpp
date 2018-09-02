#include<iostream>
#include<map>
using namespace std;
int main() {
  map<string, int> roman;
  roman.insert(make_pair("M", 1000));
  roman.insert(make_pair("CM", 900));
  roman.insert(make_pair("D",  500));
  roman.insert(make_pair("CD", 400));
  roman.insert(make_pair("C",  100));
  roman.insert(make_pair("XC",  90));
  roman.insert(make_pair("L",   50));
  roman.insert(make_pair("XL",  40));
  roman.insert(make_pair("X",   10));
  roman.insert(make_pair("IX",   9));
  roman.insert(make_pair("V",    5));
  roman.insert(make_pair("IV",   4));
  roman.insert(make_pair("I",    1));
  string s;
  cin>>s;
  int res = 0;
  map<string, int>::iterator i = roman.begin();
  int j = 0, ind = 0;
  while(j<s.size()) {
    string temp;
    temp.push_back(s[j]);
    temp.push_back(s[j+1]);
    if(roman.find(temp) == roman.end())
      temp.pop_back();
    else
      j++;

    res += roman[temp];
    j++;
  }
  cout<<res;

}
