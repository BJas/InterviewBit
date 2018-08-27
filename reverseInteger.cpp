#include<iostream>
#include<string>
#include<climits>
using namespace std;
bool stringCheck(string intStr, string intMax) {
  if(intStr.size()>intMax.size())
    return true;
  else if(intStr.size()<intMax.size())
    return false;
  else
    for(int i=0; i<intStr.size(); i++) {
      if(intStr[i]>intMax[i]) return true;
      else if(intStr[i]>intMax[i]) return false;
    }
  return false;
}
int main() {
  int A;
  cin>>A;
  string intStr = to_string(A);
  string intMax = to_string(INT_MAX);
  cout<<A<<endl;
  cout<<intStr<<endl;
  if(stringCheck(intStr, intMax)) cout<<"OVERFLOW";
  else {
    reverse(intStr.begin(), intStr.end());
    int res = stoi(intStr);
    cout<<res;
  }
  return 0;
}
