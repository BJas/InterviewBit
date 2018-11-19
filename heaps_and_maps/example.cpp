#include <iostream>
using namespace std;

int main()
{
char inchar = 'A';
switch (inchar)
{
case 'A' :
    cout << "choice A \n" ;
case 'B' :
    cout << "choice B ";
case 'C' :
case 'D' :
case 'E' :
default:
    cout << "No Choice" ;
    return 0;
}
} 
