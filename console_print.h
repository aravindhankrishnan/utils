#pragma once

#include <iostream>

namespace utils {

class ConsolePrint
{
  protected:

  public:

    ConsolePrint ()
    {
    }

    ~ConsolePrint ()
    {
    }

    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    ConsolePrint& operator << (const StandardEndLine manip);

    ConsolePrint& operator () (const std::string& message_type);
    ConsolePrint& operator << (const std::string str);
    ConsolePrint& operator << (const char* str);
    ConsolePrint& operator << (const wchar_t* str);
    ConsolePrint& operator << (const char c);
    ConsolePrint& operator << (const unsigned char c);
    ConsolePrint& operator << (const int n);
    ConsolePrint& operator << (const unsigned int n);
    ConsolePrint& operator << (const double d);
    ConsolePrint& operator << (const float f);
    ConsolePrint& operator << (const long l);
    ConsolePrint& operator << (const unsigned long l);

  private:

};

static ConsolePrint console_print;

}
