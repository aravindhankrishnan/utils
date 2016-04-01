#include "getfilebasename.h"
using namespace std;

namespace utils {

string getfilebasename (string name)
{
  size_t pos1 = name.find_last_of ("/");
  size_t pos2 = name.find_first_of (".", pos1+1);
  return name.substr (pos1+1, pos2-pos1-1);
}

}
