#pragma once

#include <iostream>
#include <exception>
#include <cmath>

#include <boost/date_time/posix_time/posix_time.hpp>

namespace utils {

namespace Bp = boost::posix_time;

class Timer
{

  public:

    Timer ()
    {
    }

    // just to maintain backward compatibility
    Timer (const std::string in_resolution)
    {
    }

    void tic ();

    std::string toc ();

    // just to maintain backward compatibility
    std::string getResolution ();

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
