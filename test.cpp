#include <iostream>
#include <unistd.h>
using namespace std;

#include "utils.h"
#include "profiler.h"


static
void test_integer_sequence1(int argc, char *argv[])
{
    PROFILE_FUNCTION

  if (argc < 2) {
    cout << "Enter the limit as argument ..\n";
    cout << "Numbers are generated in the interval [0, limit]\n";
    return;
  }

  cout << "for loop..\n";
  int limit = atoi (argv[1]);
  utils::Timer timer;
  timer.tic();
  int i = 0;
  for (i = 0; i <= limit; i++) {
    //cout << i << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;
  //using float_seconds = std::chrono::duration<float>;
  //float_seconds s = timer.toc();
  cout << " Time taken : "<< timer.secondsClock(timer.toc()) << endl;
  cout << " Time taken : "<< timer.millisecondsClock(timer.toc()) << endl;
  cout << " Time taken : "<< timer.microsecondsClock(timer.toc()) << endl;

  cout << "sequence object..\n";
  timer.tic();
  utils::IntegerSequence sequence (0, limit, 1);
  int j = 0;
  while (sequence(j)) {
    //cout << j << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;

  timer.tic();
  sequence(2*limit, 3*limit);
  j = 0;
  while (sequence(j)) {
    //cout << j << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;
}

static
void test_integer_sequence (int argc, char *argv[])
{
    PROFILE_FUNCTION

  if (argc < 2) {
    cout << "Enter the limit as argument ..\n";
    cout << "Numbers are generated in the interval [0, limit]\n";
    return;
  }

  cout << "for loop..\n";
  int limit = atoi (argv[1]);
  utils::Timer timer;
  timer.tic();
  int i = 0;
  for (i = 0; i <= limit; i++) {
    //cout << i << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;
  //using float_seconds = std::chrono::duration<float>;
  //float_seconds s = timer.toc();
  cout << " Time taken : "<< timer.secondsClock(timer.toc()) << endl;
  cout << " Time taken : "<< timer.millisecondsClock(timer.toc()) << endl;
  cout << " Time taken : "<< timer.microsecondsClock(timer.toc()) << endl;

  cout << "sequence object..\n";
  timer.tic();
  utils::IntegerSequence sequence (0, limit, 1);
  int j = 0;
  while (sequence(j)) {
    //cout << j << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;

  timer.tic();
  sequence(2*limit, 3*limit);
  j = 0;
  while (sequence(j)) {
    //cout << j << " ";
  }
  //cout << limit << " Time taken : "<< timer.toc() << endl;
}

int main (int argc, char *argv[])
{
    {
        PROFILE_BLOCK("main")
        sleep(1);
  test_integer_sequence (argc, argv);
  test_integer_sequence (argc, argv);

  test_integer_sequence1(argc, argv);
  test_integer_sequence1(argc, argv);
    }
  utils::printProfilers();

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
