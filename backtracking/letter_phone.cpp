#include<iostream>
<<<<<<< HEAD
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
=======
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const char hashTable[10][5] = {"0", "1", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

void getCombination(string str, int index, vector<string> &result, string res) {

  if(str.size()==index) {
    result.push_back(res);
    return;
  }
  int digit = str[index] - '0';
  for(int i=0; i<strlen(hashTable[digit]); i++) {
    res.push_back(hashTable[digit][i]);
    getCombination(str, index+1, result, res);
    res.pop_back();
  }
}
int main() {
  string str, temp = "";
  cin>>str;
  vector<string> result;
  getCombination(str, 0, result, temp);
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
>>>>>>> 39d3be2f845a8addb9b47d2eee5540aac2446b28
  return 0;
}
