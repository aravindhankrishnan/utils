#include <iostream>
using namespace std;

#include "timer.h"

int main (int argc, char *argv[])
{
  string timer_resolution = "microseconds";
  utils::Timer timer (timer_resolution);
  timer.tic ();
  sleep (3);
  cout << timer.toc () << " " << timer_resolution << endl;
  return 0;
}
