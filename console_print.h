#pragma once

#include <iostream>

//Black        0;30     Dark Gray     1;30
//Red          0;31     Light Red     1;31
//Green        0;32     Light Green   1;32
//Brown/Orange 0;33     Yellow        1;33
//Blue         0;34     Light Blue    1;34
//Purple       0;35     Light Purple  1;35
//Cyan         0;36     Light Cyan    1;36
//Light Gray   0;37     White         1;37

namespace utils {

class ConsolePrint
{
  protected:

  public:

    ConsolePrint ()
    {
      normal_escape_sequence = "\033[0m";
    }

    ~ConsolePrint ()
    {
    }

    std::string color_escape_sequence,
                normal_escape_sequence;

    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    ConsolePrint& operator << (const StandardEndLine manip);

    ConsolePrint& operator () (const std::string& message_type);
    ConsolePrint& operator << (const std::string& str);
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
