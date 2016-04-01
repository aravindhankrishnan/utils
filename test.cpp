#include <iostream>
using namespace std;

#include "timer.h"
#include "getfilename.h"
#include "systemtime.h"
#include "getbasepath.h"
#include "getfilebasename.h"

int main (int argc, char *argv[])
{
  string input = argv[1];

  cout << utils::getbasepath (input) << endl;
  cout << utils::getfilebasename (input) << endl;

  //string timestr = "";
  //utils::getSystemTime (timestr);
  //cout <<  timestr << endl;

  //string basename = "test";
  //string extension = "txt";

  //cout << utils::getfilename (basename, extension) << endl;


  //string timer_resolution = "microseconds";
  //utils::Timer timer (timer_resolution);
  //timer.tic ();
  //sleep (3);
  //cout << timer.toc () << " " << timer_resolution << endl;
  return 0;
}
