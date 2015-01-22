#include "systemtime.h"

//#include <cstring>
#include <cstdio>
using namespace std;

namespace utils {

//void getSystemTime (string& time_str)
//{
//  time_t rawtime;
//  struct tm* timeinfo;
//  char buffer[80];
//
//  time (&rawtime);
//  timeinfo = localtime (&rawtime);
//
//  strftime (buffer, 80, "%Y-%m-%d--%H-%M-%S", timeinfo);
//  time_str = buffer;
//}

void getSystemTime (string& time_str)
{
  struct timeval tv;
  struct timezone tz;
  struct tm *tm;

  gettimeofday (&tv, &tz);
  tm = localtime (&tv.tv_sec);
  char buffer[80];
  sprintf (buffer, "%02d-%02d-%02d-%03ld", tm->tm_hour, tm->tm_min, tm->tm_sec, (tv.tv_usec/1000));
  time_str = buffer;
}

}
