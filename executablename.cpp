#include "executablename.h"

#include <unistd.h>

namespace utils {

string getExecutableName ()
{
  char buffer[1024];
  fill_n (buffer, 1024, '\0');
  readlink ("/proc/self/exe", buffer, 1024);

  string str = buffer;
  string name = "";

  size_t pos;
  if ( (pos = str.rfind ("/")) != string::npos) {
    name = str.substr (pos+1);
  }
  return name;
}

}
