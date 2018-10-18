#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > processSudoku(vector<string> &v) {
  vector<vector<int> > sudoku(9, vector<int>(9));
  for(int i=0; i<v.size(); i++) {
    for(int j=0; j<v[i].size(); j++) {
      if(v[i][j]=='.')
        sudoku[i][j] = 0;
      else
        sudoku[i][j] = v[i][j]-'0';
    }
  }
  return sudoku;
}
bool isFull(vector<vector<int> > &v) {
  for(int i=0; i<v.size(); i++) {
    for(int j=0; j<v[i].size(); j++) {
      if(v[i][j]==0)
        return false;
    }
  }
  return true;
}
vector<int> getEmptyField(vector<vector<int> > &v) {
  vector<int> empty;
  for(int i=0; i<v.size(); i++) {
    for(int j=0; j<v[i].size(); j++) {
      if(v[i][j]==0) {
        empty.push_back(i);
        empty.push_back(j);
        return empty;
      }
    }
  }
  return empty;
}
vector<int> getPossible(vector<vector<int> > &sudoku, int i, int j) {
  vector<int> result(9);
  for(int x=0; x<9; x++) {
    if(sudoku[x][j]>0) {
      result[sudoku[x][j]-1] = 1;
    }
  }
  for(int y=0; y<9; y++) {
    if(sudoku[i][y]>0) {
      result[sudoku[i][y]-1] = 1;
    }
  }
  int l = i-i%3, k = j-j%3;
  for(int x=l; x<l+3; x++) {
    for(int y=k; y<k+3; y++) {
      if(sudoku[x][y]>0) {
        result[sudoku[x][y]-1] = 1;
      }
    }
  }
  return result;
}
bool sudokuSolver(vector<vector<int> > &sudoku) {
  if(isFull(sudoku)) {
    return true;
  }
  vector<int> empties;
  empties = getEmptyField(sudoku);
  int i = empties[0];
  int j = empties[1];
  vector<int> possibility;
  possibility = getPossible(sudoku, i, j);

  for(int x=0; x<possibility.size(); x++) {
    if(possibility[x]==0) {
      sudoku[i][j] = x+1;
      if(sudokuSolver(sudoku))
        return true;
      sudoku[i][j] = 0;
    }
  }
  return false;
}
int main() {
  vector<string> v;
  string s;
  for(int i=0; i<9; i++) {
    cin>>s;
    v.push_back(s);
  }
  vector<vector<int> > sudoku;
  sudoku = processSudoku(v);
  sudokuSolver(sudoku);
  cout<<"List is:\n";
  for(int i=0; i<sudoku.size(); i++) {
    for(int j=0; j<sudoku[i].size(); j++) {
      cout<<sudoku[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
