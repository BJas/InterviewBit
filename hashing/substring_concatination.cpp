#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
vector<int> getConcat(string str, vector<string> &words) {
  int k = words[0].size();
  int len = words.size();
  int s_words = k*len;
  vector<int> result;
  map<string, int> m;
  if (s_words > str.size())
        return result; 
  for(int i=0; i<words.size(); i++)
    m[words[i]]++;

  for(int i=0; i<str.size() - k; i++) {
      map<string, int> temp(m);
      int j = i;
      while(j<i+s_words) {
        string w = str.substr(j, k);
        if(temp.find(w)==temp.end()) {
          break;
        } else {
          temp[w]--;
        }

        j+=k;
      }

      int count = 0;

      for(auto itr = temp.begin(); itr!=temp.end(); itr++) {
        if(itr->second>0)
          count++;
      }

      if(count==0)
        result.push_back(i);
  }
  return result;
}
int main() {
  int n;
  string x, t;
  cin>>t;
  cin>>n;
  vector<string> v;
  for(int i=0; i<n; i++) {
    cin>>x;
    v.push_back(x);
  }
  vector<int> result;
  result = getConcat(t, v);
  for(int i=0; i<result.size(); i++) {
    cout<<result[i]<<" ";
  }
  return 0;
}
