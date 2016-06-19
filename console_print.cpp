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
      //std::cout <<  "\033[0;37m";
      std::cout << "INFO";
      //std::cout <<  "\033[0m";
      std::cout << "] ";
      color_escape_sequence = normal_escape_sequence;

    CASE_("warn")

      std::cout << "[";
      std::cout <<  "\033[0;36m";
      std::cout << "WARN";
      std::cout <<  "\033[0m";
      std::cout << "] ";
      color_escape_sequence = "\033[0;36m";

    CASE_("error")

      std::cout << "[";
      std::cout << "\033[0;31m";
      std::cout << "\033[1m";
      //std::cout << "\033#6";
      std::cout << "ERROR";
      std::cout <<  "\033[0m";
      std::cout << "] ";
      color_escape_sequence = "\033[0;31m";
      color_escape_sequence += "\033[1m";

    DEFAULT_

      ostringstream ostr;
      ostr << "Unknown message type : " << message_type << "\n";
      throw std::runtime_error (ostr.str ());

  END_STRING_SWITCH_

  return *this;
}

ConsolePrint& ConsolePrint::operator << (const std::string& str)
{
  cout << color_escape_sequence;
  cout << str;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char* str)
{
  cout << color_escape_sequence;
  cout << str;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const wchar_t* str)
{
  cout << color_escape_sequence;
  cout << str;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned char c)
{
  cout << color_escape_sequence;
  cout << c;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char c)
{
  cout << color_escape_sequence;
  cout << c;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const int n)
{
  cout << color_escape_sequence;
  cout << n;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned int n)
{
  cout << color_escape_sequence;
  cout << n;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const double d)
{
  cout << color_escape_sequence;
  cout << d;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const float f)
{
  cout << color_escape_sequence;
  cout << f;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const StandardEndLine manip)
{
  cout << color_escape_sequence;
  cout << endl;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const long l)
{
  cout << color_escape_sequence;
  cout << l;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned long l)
{
  cout << color_escape_sequence;
  cout << l;
  color_escape_sequence = normal_escape_sequence;
  cout << color_escape_sequence;
  return *this;
}

}
