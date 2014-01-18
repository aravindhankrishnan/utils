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
      resolution = "milliseconds";
    }

    Timer (const string in_resolution)
    {
      resolution = in_resolution;
    }

    void tic ()
    {
      if (resolution.compare ("seconds") == 0) {
        start = Bp::second_clock::local_time ();
      }
      else if (resolution.compare ("milliseconds") == 0) {
        start = Bp::microsec_clock::local_time ();
      }
      else if (resolution.compare ("microseconds") == 0) {
        start = Bp::microsec_clock::local_time ();
      }
      else {
        throw std::runtime_error ("Invalid resolution type set in Timer .. ");
      }
    }

    long toc () 
    {
      if (resolution.compare ("seconds") == 0) {
        end = Bp::second_clock::local_time ();
        return (end-start).total_seconds ();
      }
      else if (resolution.compare ("milliseconds") == 0) {
        end = Bp::microsec_clock::local_time ();
        return (end-start).total_milliseconds ();
      }
      else if (resolution.compare ("microseconds") == 0) {
        end = Bp::microsec_clock::local_time ();
        return (end-start).total_microseconds ();
      }
    }


    string getResolution ()
    {
      string res = "";
      if (resolution.compare ("milliseconds") == 0) {
        res = " msec";
      }
      else if (resolution.compare ("microseconds") == 0) {
        res = " misec";
      }
      else if (resolution.compare ("seconds") == 0) {
        res = " sec";
      }
      return res;
    }

  private:

    Bp::ptime start;
    Bp::ptime end;

    string resolution;

};


}
