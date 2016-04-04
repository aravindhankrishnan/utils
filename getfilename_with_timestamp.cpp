#include "getfilename_with_timestamp.h"
#include "systemtime.h"
using namespace std;

namespace utils {

string getFilenameWithTimeStamp (const string basename, const string extension)
{
  string time_str  = "";
  utils::getSystemTime (time_str);

  string filename = basename + string ("-") + time_str + string (".") + extension;
  return filename;
}


}
