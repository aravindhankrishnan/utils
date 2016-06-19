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
      std::cout << "INFO";
      std::cout << "] ";
      color_escape_sequence = default_system_color;

    CASE_("warn")

      std::cout << "[";
      std::cout <<  color_cyan;
      std::cout << "WARN";
      std::cout <<  default_system_color;
      std::cout << "] ";
      color_escape_sequence = color_cyan;

    CASE_("error")

      std::cout << "[";
      std::cout << color_red;
      std::cout << font_bold;
      std::cout << "ERROR";
      std::cout <<  default_system_color;
      std::cout << "] ";
      color_escape_sequence = color_red;
      color_escape_sequence += font_bold;

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
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char* str)
{
  cout << color_escape_sequence;
  cout << str;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const wchar_t* str)
{
  cout << color_escape_sequence;
  cout << str;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned char c)
{
  cout << color_escape_sequence;
  cout << c;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const char c)
{
  cout << color_escape_sequence;
  cout << c;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const int n)
{
  cout << color_escape_sequence;
  cout << n;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned int n)
{
  cout << color_escape_sequence;
  cout << n;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const double d)
{
  cout << color_escape_sequence;
  cout << d;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const float f)
{
  cout << color_escape_sequence;
  cout << f;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const StandardEndLine manip)
{
  cout << color_escape_sequence;
  cout << endl;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const long l)
{
  cout << color_escape_sequence;
  cout << l;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

ConsolePrint& ConsolePrint::operator << (const unsigned long l)
{
  cout << color_escape_sequence;
  cout << l;
  color_escape_sequence = default_system_color;
  cout << color_escape_sequence;
  return *this;
}

}
