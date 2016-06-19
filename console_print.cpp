#include "console_print.h"
#include "stringswitch.h"

#include <sstream>
#include <stdexcept>
using namespace std;

namespace utils {

ConsolePrint& ConsolePrint::operator () (const std::string& message_type)
{
  BEGIN_STRING_SWITCH_(message_type)

    CASE_("info")

      std::cout << "[";
      std::cout <<  "\033[0;37m";
      std::cout << "INFO";
      std::cout <<  "\033[0m";
      std::cout << "] ";

    CASE_("warn")

      std::cout << "[";
      std::cout <<  "\033[0;36m";
      std::cout << "WARN";
      std::cout <<  "\033[0m";
      std::cout << "] ";

    CASE_("error")

      std::cout << "[";
      std::cout <<  "\033[0;31m";
      std::cout << "ERROR";
      std::cout <<  "\033[0m";
      std::cout << "] ";

    DEFAULT_

      ostringstream ostr;
      ostr << "Unknown message type : " << message_type << "\n";
      throw std::runtime_error (ostr.str ());

  END_STRING_SWITCH_

  return *this;
}

ConsolePrint& ConsolePrint::operator << (const std::string str)
{
  cout << str;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char* str)
{
  cout << str;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const wchar_t* str)
{
  cout << str;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned char c)
{
  cout << c;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char c)
{
  cout << c;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const int n)
{
  cout << n;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned int n)
{
  cout << n;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const double d)
{
  cout << d;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const float f)
{
  cout << f;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const StandardEndLine manip)
{
  cout << endl;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const long l)
{
  cout << l;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned long l)
{
  cout << l;
  return *this;
}

}
