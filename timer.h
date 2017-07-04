#pragma once

#include <iostream>
#include <chrono>

namespace utils {

class Timer {

  public:

    Timer()
    {
    }

    void tic();

    std::string secondsClock(const std::chrono::microseconds& msec);
    std::string millisecondsClock(const std::chrono::microseconds& msec);
    std::string microsecondsClock(const std::chrono::microseconds& msec);

    std::chrono::microseconds toc();

  private:

    std::chrono::steady_clock::time_point start,
                                         end;
};

}
