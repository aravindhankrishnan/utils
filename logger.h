#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

class Logger
{
  protected:

  public:

    Logger ();

    Logger (const char* filename);

    Logger (const std::string& filename);

    void init (const std::string& filename);

    ~Logger ();

    void open (const std::string filename);


    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    Logger& operator << (StandardEndLine manip);

    
    Logger& operator << (const char* str);
    Logger& operator << (const wchar_t* str);
    Logger& operator << (const std::string str);
    Logger& operator << (const char c);
    Logger& operator << (const int n);
    Logger& operator << (const unsigned int n);
    Logger& operator << (const double d);

  private:

    std::ofstream ofile;
    std::string filename;
};
