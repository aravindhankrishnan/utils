#include "logger.h"
using namespace std;

Logger::Logger ()
{
  //filename = "log.txt";
  //ofile.open (filename.c_str ());

  //if (!ofile) {
  //  string error_msg = string ("Cannot open file ").append (filename);
  //  throw std::runtime_error (error_msg);
  //}
}

Logger::Logger (const char* filename)
{
  this->filename = filename;
  ofile.open (filename);

  if (!ofile) {
    string error_msg = string ("Cannot open file ").append (filename);
    throw std::runtime_error (error_msg);
  }
}

Logger::Logger (const string& filename)
{
  this->filename = filename;
  ofile.open (filename.c_str ());

  if (!ofile) {
    string error_msg = string ("Cannot open file ").append (filename);
    throw std::runtime_error (error_msg);
  }
}

void Logger::init (const string& filename)
{
  this->filename = filename;
  ofile.open (filename.c_str ());

  if (!ofile) {
    string error_msg = string ("Cannot open file ").append (filename);
    throw std::runtime_error (error_msg);
  }
}

Logger::~Logger ()
{
  ofile.close ();
}


void Logger::open (const string filename)
{
  ofile.close ();
  ofile.open (filename.c_str ());
  if (!ofile) {
    string error_msg = string ("Cannot open file ").append (filename);
    throw std::runtime_error (error_msg);
  }
  cout << "Opened file " << filename << endl;
}

Logger& Logger::operator << (StandardEndLine manip)
{
  manip(std::cout);
  ofile << "\n";
  ofile.flush ();
  return *this;
}

Logger& Logger::operator << (const char* str)
{
  cout << str;
  ofile << str;
  ofile.flush ();
  return *this;
}


Logger& Logger::operator << (const wchar_t* str)
{
  cout << str;
  ofile << str;
  ofile.flush ();
  return *this;
}

Logger& Logger::operator << (const string str)
{
  cout << str;
  ofile << str;
  ofile.flush ();
  return *this;
}

Logger& Logger::operator << (const char c)
{
  cout << c;
  ofile << c;
  ofile.flush ();
  return *this;
}

Logger& Logger::operator << (const int n)
{
  cout << n;
  ofile << n;
  ofile.flush ();
  return *this;
}


Logger& Logger::operator << (const unsigned int n)
{
  cout << n;
  ofile << n;
  ofile.flush ();
  return *this;
}

Logger& Logger::operator << (const double d)
{
  cout << d;
  ofile << d;
  ofile.flush ();
  return *this;
}
