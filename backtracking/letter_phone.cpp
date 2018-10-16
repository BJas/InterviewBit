#include<iostream>
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
  return 0;
}
