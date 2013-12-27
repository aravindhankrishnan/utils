#include "getfilename.h"
#include "systemtime.h"

namespace utils {

string getfilename (const string basename, const string extension)
{
  string time_str  = "";
  utils::getSystemTime (time_str);

  string filename = basename + string ("-") + time_str + string (".") + extension;
  return filename;
}


}
