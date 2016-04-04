#include <iostream>
using namespace std;

#include "utils.h"

static
void test_integer_sequence (int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Enter the limit as argument ..\n";
    cout << "Numbers are generated in the interval [0, limit]\n";
    return;
  }

  cout << "for loop..\n";
  int limit = atoi (argv[1]);
  string time_elapsed = "";
  utils::Timer timer;
  timer.tic ();
  int i = 0;
  for (i = 0; i <= limit; i++) {
    //cout << i << " ";
  }
  time_elapsed = timer.toc ();
  cout << limit << " Time taken : "<< time_elapsed << endl;

  cout << "sequence object..\n";
  timer.tic ();
  utils::IntegerSequence sequence (0, limit, 1);
  int j = 0;
  while (sequence (j)) {
    //cout << j << " ";
  }
  time_elapsed = timer.toc ();
  cout << limit << " Time taken : "<< time_elapsed << endl;

  timer.tic ();
  sequence (2*limit, 3*limit);
  j = 0;
  while (sequence (j)) {
    //cout << j << " ";
  }
  time_elapsed = timer.toc ();
  cout << limit << " Time taken : "<< time_elapsed << endl;
}

int main (int argc, char *argv[])
{
  test_integer_sequence (argc, argv);

  //string input = argv[1];

  //cout << utils::getbasepath (input) << endl;
  //cout << utils::getfilebasename (input) << endl;

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
