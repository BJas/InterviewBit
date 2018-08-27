#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;
void repeatedNumber(vector<int> &a) {
  for(int i=0; i<a.size(); i++) {
    if(a[abs(a[i])-1] > 0) {
      a[abs(a[i])-1] = -a[abs(a[i])-1];
    } else {
      printf("repeated number %d\n", abs(a[i]));
    }
  }
  for(int j=0; j<a.size(); j++) {
    if(a[j] > 0) {
      printf("missed number %d\n", j+1);
    }
  }
}
int main() {
  vector<int> v;
  v.push_back(4);
  v.push_back(3);
  v.push_back(5);
  v.push_back(5);
  v.push_back(1);
  repeatedNumber(v);
  return 0;
}
