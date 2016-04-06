#include "getfileextension.h"
using namespace std;

namespace utils {

string getfileExtension (const string name)
{
  size_t pos = name.find_last_of (".");
  return name.substr (pos+1);
}

}
