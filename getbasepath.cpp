#include "getbasepath.h"

#include <iostream>
using namespace std;

namespace utils {

string getbasepath (const string filename)
{
  size_t pos = filename.find_last_of ("/");
  return filename.substr (0, pos+1);
}

}
