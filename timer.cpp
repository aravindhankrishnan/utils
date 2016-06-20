#include "timer.h"
#include <sstream>
using namespace std;

namespace utils {

void Timer::tic ()
{
  start = std::chrono::high_resolution_clock::now ();
}

std::string Timer::toc () 
{
  end = std::chrono::high_resolution_clock::now ();
  auto d = end - start;
  long long val = std::chrono::duration_cast <std::chrono::nanoseconds> (d).count ();

  // 1 milli second = 1000 microseconds
  // 1 second = 1000 milliseconds
  // 1 min = 60 seconds
  // 1 hour = 60 minutes

  microseconds = val % 1000;
  val /= 1000;
  milliseconds = val % 1000;
  val /= 1000;
  seconds = val % 60;
  val /= 60;
  minutes = val % 60;
  hours = val / 60;

  std::ostringstream ostr;
  
  if (hours) {
    ostr << hours << " hours ";
  }
  if (minutes) {
    ostr << minutes << " minutes ";
  }
  if (seconds) {
    ostr << seconds << " seconds ";
  }
  if (milliseconds) {
    ostr << milliseconds << " milliseconds ";
  }
  if (microseconds) {
    ostr <<  microseconds << " microseconds.";
  }
  return ostr.str ();
}

// just to maintain backward compatibility
std::string Timer::getResolution ()
{
  return "";
}

}
