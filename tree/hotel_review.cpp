#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct Node {
  map<char, Node*> children;
  bool isEndOfWord;
  Node() {
    isEndOfWord = false;
  }
};
Node* getTrie(string keys, Node* root) {
  if(!root) {
    root = new Node();
    root->children[keys[0]] = NULL;
  }
  Node* current;
  int i = 0, j;
  while(i < keys.length()) {
    j = i;
    current = root;
    while(j < keys.length() && keys[j] != '_') {
      Node* node = current->children[keys[j]];
      if(!node) {
        node = new Node();
        current->children[keys[j]] = node;
      }
      current = node;
      j++;
    }
    current->isEndOfWord = true;
    i = j + 1;
  }
  return root;
}
int search(Node* root, string temp) {
  int counter = 0;
  int i = 0, j;

  while(i < temp.length()) {
    j = i;
    Node* current = root;
    bool isChecked = false;

    while(j < temp.length() && temp[j] != '_') {
      if(current->children.find(temp[j]) == current->children.end()) {
        isChecked = true;
      }
      if(!isChecked) current = current->children[temp[j]];
      j++;
    }

    if(!isChecked && current->isEndOfWord)
      counter++;

    i = j + 1;
  }
  return counter;
}
int main() {
  string s, x;
  cin>>s;
  int n;
  cin>>n;
  vector<string> str;
  for(int i=0; i<n; i++) {
    cin>>x;
    str.push_back(x);
  }

  Node* root = NULL;
  root = getTrie(s, root);

  // to get equal counts
  map<int, vector<int> > res;

  for(int i=0; i<n; i++) {
    int count = search(root, str[i]);
    res[count].push_back(i);
  }

  map<int, vector<int> >::iterator it;
  vector<int> result;

  // Reverse vector to get descending order
  for(it = res.begin(); it != res.end(); it++) {
    vector<int> counts = it->second;
    reverse(counts.begin(), counts.end());

    for(int i=0; i<counts.size(); i++) {
      cout<<it->first<<" "<<counts[i]<<endl;
      result.push_back(counts[i]);
    }

  }

  reverse(result.begin(), result.end());

  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";

  return 0;
}
