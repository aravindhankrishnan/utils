#pragma once

#include <iostream>
#include <exception>
using namespace std;

#include <boost/date_time/posix_time/posix_time.hpp>

namespace utils
{


  namespace Bp = boost::posix_time;

class Timer
{
  public:
    Timer ()
    {
      resolution_ = "milliseconds";
    }

    Timer (string resolution)
    {
      resolution_ = resolution;
    }

    void tic ()
    {
      if (resolution_.compare ("seconds") == 0) {
        start = Bp::second_clock::local_time ();
      }
      else if (resolution_.compare ("milliseconds") == 0) {
        start = Bp::microsec_clock::local_time ();
      }
      else if (resolution_.compare ("microseconds") == 0) {
        start = Bp::microsec_clock::local_time ();
      }
      else {
        throw std::runtime_error ("Invalid resolution type set in Timer .. ");
      }
    }

    long toc () 
    {
      if (resolution_.compare ("seconds") == 0) {
        end = Bp::second_clock::local_time ();
        return (end-start).total_seconds ();
      }
      else if (resolution_.compare ("milliseconds") == 0) {
        end = Bp::microsec_clock::local_time ();
        return (end-start).total_milliseconds ();
      }
      else if (resolution_.compare ("microseconds") == 0) {
        end = Bp::microsec_clock::local_time ();
        return (end-start).total_microseconds ();
      }
    }


  private:

    Bp::ptime start;
    Bp::ptime end;

    string resolution_;

};


}
