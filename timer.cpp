#include "timer.h"

#include <sstream>
using namespace std;

namespace utils {

void Timer::tic() {
  start = std::chrono::steady_clock::now();
}

std::chrono::microseconds Timer::toc()  {
  end = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end-start);
}

std::string Timer::secondsClock(const std::chrono::microseconds& msec) {
  using float_seconds = std::chrono::duration<float>;
  float_seconds fs = msec;
  ostringstream ostr;
  ostr << fs.count() << " sec";
  return ostr.str();
}

std::string Timer::millisecondsClock(const std::chrono::microseconds& msec) {
  using float_milliseconds = std::chrono::duration<float, std::milli>;
  float_milliseconds fms = msec;
  ostringstream ostr;
  ostr << fms.count() << " msec";
  return ostr.str();
}

std::string Timer::microsecondsClock(const std::chrono::microseconds& msec) {
  using float_microseconds = std::chrono::duration<float, std::micro>;
  float_microseconds fus = msec;
  ostringstream ostr;
  ostr << fus.count() << " usec";
  return ostr.str();
}

}
