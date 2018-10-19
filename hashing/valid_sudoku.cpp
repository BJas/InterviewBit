#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool checkRow(int row, vector<string> &sudoku) {
  map<char, bool> checker;
  for(int j=0; j<9; j++) {
    if(sudoku[row][j] != '.') {
      if(checker.find(sudoku[row][j]) != checker.end())
        return false;
      checker[sudoku[row][j]] = true;
    }
  }
  return true;
}
bool checkCol(int col, vector<string> &sudoku) {
  map<char, bool> checker;
  for(int j=0; j<9; j++) {
    if(sudoku[j][col] != '.') {
      if(checker.find(sudoku[j][col]) != checker.end())
        return false;
      checker[sudoku[j][col]] = true;
    }
  }
  return true;
}
bool checkSquare(int row, int col, vector<string> &sudoku) {
  map<char, bool> checker;
  int l = row-row%3, r = col-col%3;
  for(int i=l; i<l+3; i++) {
    for(int j=r; j<r+3; j++) {
      if(sudoku[i][j] != '.') {
        if(checker.find(sudoku[i][j]) != checker.end())
          return false;
        checker[sudoku[i][j]] = true;
      }
    }
  }
  return true;
}
bool checkToValid(int row, int col, vector<string> &sudoku) {
  return checkCol(col, sudoku) && checkRow(row, sudoku) && checkSquare(row, col, sudoku);
}
bool isValid(vector<string> &sudoku) {
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      if(sudoku[i][j] != '.' && !checkToValid(i, j, sudoku))
          return false;
    }
  }
  return true;
}
int main() {
  string s;
  vector<string> sudoku;
  for(int i=0; i<9; i++) {
    cin>>s;
    sudoku.push_back(s);
  }
  bool result = isValid(sudoku);
  cout<<result;
  return 0;
}
