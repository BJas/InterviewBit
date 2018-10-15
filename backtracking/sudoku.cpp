#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<int> > getStrToInt(vector<string> &str) {
  vector<vector<int> > sudoku(9, vector<int>(9));
  for(int i=0; i<str.size(); i++) {
    for(int j=0; j<str[i].size(); j++) {
      if(str[i][j]=='.')
        sudoku[i][j] = 0;
      else
        sudoku[i][j] = str[i][j] - '0';
    }
  }
  return sudoku;
}
vector<string> getIntToStr(vector<vector<int> > &v) {
  vector<string> str;
  string temp;
  for(int i=0; i<v.size(); i++) {
    temp = "";
    for(int j=0; j<v[i].size(); j++) {
      char ch = v[i][j] + '0';
      temp += ch;
    }
    str.push_back(temp);
  }
  return str;
}
bool isFull(vector<vector<int> > &sudoku) {
  for(int i=0; i<sudoku.size(); i++)
    for(int j=0; j<sudoku.size(); j++)
      if(sudoku[i][j]==0)
        return false;
  return true;
}
vector<int> getPossible(vector<vector<int> > &sudoku, int row, int col) {
  vector<int> possibles;
  for(int i=0; i<9; i++)
    possibles.push_back(0);

  for(int i=0; i<9; i++) {
    if(sudoku[i][col]>0)
      possibles[sudoku[i][col]-1] = 1;
  }

  for(int j=0; j<9; j++) {
    if(sudoku[row][j]>0)
      possibles[sudoku[row][j]-1] = 1;
  }

  int l = row-row%3, k = col-col%3;
  for(int i=l; i<l+3; i++) {
    for(int j=k; j<k+3; j++) {
        if(sudoku[i][j]>0)
          possibles[sudoku[i][j]-1] = 1;
    }
  }

  return possibles;
}
vector<int> getEmpty(vector<vector<int> > &sudoku) {
  vector<int> res;
  for(int i=0; i<sudoku.size(); i++) {
    for(int j=0; j<sudoku[i].size(); j++) {
      if(sudoku[i][j] == 0) {
        res.push_back(i);
        res.push_back(j);
        return res;
      }
    }
  }
  return res;
}
bool sudokuSolver(vector<vector<int> > &sudoku) {
  if(isFull(sudoku)) {
    return true;
  }
  vector<int> empties;
  empties = getEmpty(sudoku);
  int r = empties[0];
  int c = empties[1];
  vector<int> possibles;
  possibles = getPossible(sudoku, r, c);
  for(int i=0; i<possibles.size(); i++) {
    if(possibles[i]==0) {
      sudoku[r][c] = i+1;
      if(sudokuSolver(sudoku))
        return true;
      sudoku[r][c] = 0;
    }
  }
  return false;
}
int main() {
  vector<string> str;
  string temp1 = "3.65.84..";
  string temp2 = "52.......";
  string temp3 = ".87....31";
  string temp4 = "..3.1..8.";
  string temp5 = "9..863..5";
  string temp6 = ".5..9.6..";
  string temp7 = "13....25.";
  string temp8 = ".......74";
  string temp9 = "..52.63..";
  str.push_back(temp1);
  str.push_back(temp2);
  str.push_back(temp3);
  str.push_back(temp4);
  str.push_back(temp5);
  str.push_back(temp6);
  str.push_back(temp7);
  str.push_back(temp8);
  str.push_back(temp9);
  vector<vector<int> > sudoku;
  sudoku = getStrToInt(str);
  sudokuSolver(sudoku);
  str = getIntToStr(sudoku);
  cout<<"List is:\n";
  for(int i=0; i<str.size(); i++) {
    for(int j=0; j<str[i].size(); j++) {
      cout<<str[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
