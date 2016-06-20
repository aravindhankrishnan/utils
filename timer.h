#pragma once

#include <iostream>
#include <chrono>

namespace utils {

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


  protected:

    std::chrono::high_resolution_clock::time_point start,
                                                   end;

  private:


    long long hours,
              minutes,
              seconds,
              milliseconds,
              microseconds;
};


}
