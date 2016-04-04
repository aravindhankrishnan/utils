#include "timer.h"

namespace utils {

void Timer::tic ()
{
  start = Bp::microsec_clock::local_time ();
}

std::string Timer::toc () 
{
  end = Bp::microsec_clock::local_time ();
  long val = (end-start).total_microseconds ();

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
