#include <iostream>
using namespace std;

//Black        0;30     Dark Gray     1;30
//Red          0;31     Light Red     1;31
//Green        0;32     Light Green   1;32
//Brown/Orange 0;33     Yellow        1;33
//Blue         0;34     Light Blue    1;34
//Purple       0;35     Light Purple  1;35
//Cyan         0;36     Light Cyan    1;36
//Light Gray   0;37     White         1;37

void changeColor (const string color)
{
  if (color == "red") {
    cout <<  "\033[0;36m";
  }

  if (color == "normal") {
    cout <<  "\033[0m";
  }
}

void printErrorMessage (const string& error_msg)
{
  cout << "[";
  changeColor ("red");
  cout << "ERROR";
  changeColor ("normal");
  cout << "] ";
  cout << error_msg << "\n";
}

int main (int argc, char *argv[])
{
  printErrorMessage ("hello world");
  return 0;
}
