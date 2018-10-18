#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main() {
  int n, temp;
  cin>>n;
  map<int,string> phone;
  phone[2] = "abc";
  phone[3] = "def";
  phone[4] = "ghi";
  phone[5] = "jkl";
  phone[6] = "mno";
  phone[7] = "pqrs";
  phone[8] = "tuv";
  phone[9] = "wxyz";
  temp = n;
  vector<string> letter;
  while(temp>0) {
    int rem = temp%10;
    letter.push_back(phone[rem]);
    temp /= 10;
  }
  reverse(letter.begin(), letter.end());
  vector<string> result;
  getPhoneLetter(letter, result);
  return 0;
}
