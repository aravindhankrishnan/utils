#include <iostream>
#include <stdexcept>
#include <sstream>

namespace utils {

struct IntegerSequence
{
  int counter;

  int end,
      step;

  IntegerSequence (const int _start, const int _end, const int _step = 1)
  {
    if (_start > _end) {
      std::ostringstream ostr;
      ostr << "** IntegerSequence : start index (" << _start << ") "
           << "is greater than end index (" << _end << ") **\n";
      throw std::runtime_error (ostr.str ());
    }

    if (_step <= 0) {
      std::ostringstream ostr;
      ostr << "** IntegerSequence : Invalid step size (" << _step << ") **\n";
      throw std::runtime_error (ostr.str ());
    }

    counter = _start;
    end = _end;
    step = _step;
  }

  bool operator () (int& i);

  void operator () (const int _start, const int _end, const int _step = 1);

  ~IntegerSequence ()
  {
  }
};

}
