#include <iostream>

namespace utils {

struct IntegerSequence
{
  int counter;

  int end,
      step;

  IntegerSequence (const int _start, const int _end, const int _step)
  {
    counter = _start;
    end = _end;
    step = _step;
  }

  bool operator () (int& i);

  ~IntegerSequence ()
  {
  }
};

}
