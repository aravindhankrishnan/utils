#pragma once

#include <iostream>
#include <exception>
#include <cmath>

#include <boost/date_time/posix_time/posix_time.hpp>

namespace utils
{
  namespace Bp = boost::posix_time;

class Timer
{
  public:
    Timer ()
    {
    }

    // just to maintain backward compatibility
    Timer (const string in_resolution)
    {
    }

    void tic ()
    {
      start = Bp::microsec_clock::local_time ();
    }

    string toc () 
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
    std::string getResolution ()
    {
      return "";
    }

  private:

    Bp::ptime start;
    Bp::ptime end;

    long hours,
         minutes,
         seconds,
         milliseconds,
         microseconds;
};


}
